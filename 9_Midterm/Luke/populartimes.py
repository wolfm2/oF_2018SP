import requests
from bs4 import BeautifulSoup
import pickle
import json
import time
import urllib
from geographiclib.geodesic import Geodesic
import math
geod = Geodesic.WGS84

class placeController(object):
    def __init__(self, apiKey):
        self.apiKey = apiKey
        self.s = requests.Session()
        self.s.headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36'}

        self.lat = 40.737009
        self.lng = -73.992216

        self.placeList = []
        self.places_as_json = []

    def get_place_list(self, placeType, lat = None, lng = None):
        if lat is None:
            lat = self.lat
        if lng is None:
            lng = self.lng

        payload = {
            "location" : "{:f},{:f}".format(lat, lng),
            "rankby" : "distance", 
            "type" : placeType, 
            "key" : self.apiKey
        }

        url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json"
        res = self.s.get(url, params=payload)

        with open("url.txt", "w") as fp:
            fp.write(res.request.url)

        resData = json.loads(res.text)

        # with open("results.json", "w") as fp:
        #     json.dump(resData, fp)

        for value in resData["results"]:
            print(value)
            print("")
            self.placeList.append(place(value["name"], value["vicinity"], value["geometry"]["location"], value["place_id"]))

        time.sleep(2)

        payload = {
            "pagetoken" : resData["next_page_token"], 
            "key" : self.apiKey
        }

        url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json"
        res = self.s.get(url, params=payload)

        resData = json.loads(res.text)

        print(resData)

        for value in resData["results"]:
            print(value)
            print("")
            self.placeList.append(place(value["name"], value["vicinity"], value["geometry"]["location"], value["place_id"]))

        time.sleep(2)

        payload = {
            "pagetoken" : resData["next_page_token"], 
            "key" : self.apiKey
        }

        url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json"
        res = self.s.get(url, params=payload)

        resData = json.loads(res.text)

        for value in resData["results"]:
            print(value)
            print("")
            self.placeList.append(place(value["name"], value["vicinity"], value["geometry"]["location"], value["place_id"]))

        for value in self.placeList:
            print(value.name, value.lat, value.lng, value.placeId)

    def gen_place_json(self):
        for value in self.placeList:
            
            self.timeData = value.get_time_data()

            g = geod.Inverse(self.lat, self.lng, value.lat, value.lng)
            angle = g["azi1"]
            distance = g["s12"]

            self.places_as_json.append({
                "name" : value.name, 
                "vicinity" : value.vicinity,
                "lat" : value.lat, 
                "lng" : value.lng, 
                "placeid" : value.placeId,
                "timeData" : value.timeData,
                "angle" : angle, 
                "distance" : distance
            })

            # time.sleep(2)

        with open("data/places_as_json.json", "w") as fp:
            json.dump(self.places_as_json, fp, indent=4)

    def get_place_details(self, placeId):
        payload = {
            "placeid" : placeId, 
            "key" : self.apiKey
        }

        url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json"
        res = self.s.get(url, params=payload)

class place(object):
    def __init__(self, name, vicinity, location, placeId):
        self.name = name
        self.vicinity = vicinity
        # self.location = location
        self.lat = location["lat"]
        self.lng = location["lng"]
        self.placeId = placeId
        self.timeData = None

    def get_time_data(self):
        params_url = {
            "tbm": "map",
            "hl": "en",
            "tch": 1,
            "q": urllib.parse.quote_plus("{} {}".format(self.name, self.vicinity))
        }

        search_url = "https://www.google.com/search?" + "&".join(k + "=" + str(v) for k, v in params_url.items())
        print(search_url)

        data = requests.get(search_url).text

        jend = data.rfind("}")
        if jend >= 0:
            data = data[:jend + 1]

        jdata = json.loads(data)["d"]
        jdata = json.loads(jdata[4:])

        popular_times, rating, rating_n = None, None, None

        try:
            # get info from result array, has to be adapted if backend api changes
            info = jdata[0][1][0][14]

            rating = info[4][7]
            rating_n = info[4][8]
            popular_times = info[84][0]

        except (TypeError, IndexError):
            pass

        if popular_times is not None:

            # print(popular_times)
            print(popular_times[1])

            # sunday is 7
            # monday is 1
            # tuesday is 2
            # wednesday is 3
            # thursday is 4
            # friday is 5
            # saturday is 6
            
            for value in popular_times:
                if(value[1] is not None):
                    print(value[0])

                    for hour in value[1]:
                        if(hour[2] == ""):
                            print(hour[4], hour[1])
                        else:
                            print(hour[4], hour[2], hour[1])

                    print("")

            self.timeData = popular_times

if __name__ == '__main__':
	#Use google places api key
    testController = placeController(APIKEY_GOES_HERE)
    testController.get_place_list("restaurant")
    testController.gen_place_json()