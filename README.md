# oF_2018SP

Class oF example code is [here](https://github.com/wolfm2/oF_Examples).

Class slides are [here](https://drive.google.com/drive/folders/1a5XLCCIaZmdTavGbogB_-p-dzR81Ieeb?usp=sharing).
 You must be logged into your school account to access them.

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
  1. cd YourNewProject
  2. git add .			: Tells git to track all project files (Repeat steps 1,2 if you add new files)
  3. write your program	
  4. git commit -am "Message"	: Tells git to create a snapshot of the project.  Use a descriptive message!
  5. git status			: Tells you what git wants to change.  Verify this before pushing!
  5. git pull			: Downloads changes from your classmates
  6. git push			: Uploads changes you've made
```
For every project, some IDE files will **never** upload.  This is intentional as all environments generate huge files which don't relate to the app functionality.  The only files you need are in the "src" and (maybe) "data" directories.
