"# oF_2018SP

Class oF example code is [here](https://github.com/wolfm2/oF_Examples).

Class slides are [here](https://drive.google.com/drive/folders/1a5XLCCIaZmdTavGbogB_-p-dzR81Ieeb?usp=sharing).
 You must be logged into your school account to access them.
 
Each week during class hours submit an issue to the repository containing your first,last name as it appears in canvas.  This will be used for attendance.

When you are pushing your work, do it in the correct project/name directory.  Don't add/delete others work.  All github activity will be timestamped with your name.

For every project commit at least:

  * One or more screenshots of the program showing required features
  * A text file which lists the requirements a description of your solution and where (line number) in the code this was done
  
Optionally include a data directory but be careful with file sizes as everyone will have to download your assets!


## Using this repository

Make a github account.

Before your first push I have to make you a "contributor".  Send me an "Issue" on the github repository page and I will send you an invite.  Wait for the emailed invitation or head [here](https://github.com/wolfm2/oF_2018SP/invitations) to accept.

Clone the class repository.

[Create a new project](http://openframeworks.cc/learning/01_basics/create_a_new_project/) under the correct assignment/yourName folder.

Using a terminal:

```
  1. cd YourNewProject		: Type "cd ", drop your new project folder in the terminal, and hit enter.
  2. git add .			: Tells git to track all project files (Repeat steps 1,2 if you add new files)
  3. write some code	
  4. git commit -am "Message"	: Tells git to create a snapshot of the project.  Use a descriptive message!
  5. git status			: Tells you what git wants to change.  Verify this before pushing!
  6. git pull			: Downloads changes from your classmates
  7. git push			: Uploads changes you've made
```
You can iterate over these steps as often as needed. Every time you get a new part of your project working you should commit it so you can return to it later if needed.

For every project, some IDE files will **never** upload.  This is intentional as all environments generate huge files which don't relate to the app functionality.  The only files you need are in the "src" and (maybe) "data" directories.

## Compiling code

Select an existing project or use [project generator](http://openframeworks.cc/learning/01_basics/create_a_new_project/) to create a new project.

Using a terminal in macOS or Linux:

```
  1. cd TheProject		: Type "cd ", drop the project folder in the terminal, and hit enter.
  2. make			: Takes your c++ files and assembles an app.
  3. fix errors if any		: Any errors will prevent the program from compiling.
  4. make RunRelease		: Runs the program if it successfully compiled.
  - optionally -
  make clean			: Will delete *all* previously compiled objects and start fresh.

