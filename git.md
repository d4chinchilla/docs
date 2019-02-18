Git cheat sheet
===============


For this project, we are using git to keep track of changes to our code, and keeping our
code in four shared repositories. (including this one)

To install git on your computer, there is a tutorial availiable 
[here](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git). You should be able to
use git console commands via the git bash program, or the windows command prompt.

There are also many resources online which list the basic commands etc. and many more that go into
depth, but I will go through the basic workflow here.

Cloning
-------

In order to get a copy of the code on your local computer, you can use the command `git clone [url]`
where the url is the http address of the repository online.

Once you have cloned a repository, you can move into it using the `cd` command, and can then begin
to use git commands on that repository.

Branches
--------

Each person should work on their own branch - this is their own version of the code. The changes
they make here will not affect other people's branches, so that everyone can work without coming into
conflict. To switch to your branch do the command `git checkout [branch]` e.g. `git checkout francis`
Here is where you should make your commits.

When the changes to your branch are finished, and everything is working, the leader of the appropriate 
section of the project can then 'merge' the branches together, combining the changes you have made with
those of everyone else. This main working version of the software should be stored on the 'master' 
branch. You can view this branch in your local repository, using the command `git checkout master`, but
be sure to switch back to your own branch before making changes again!

If you are using something like git-bash, you will see the current branch in brackets on your 
command-line.

Commits
-------

When you make changes to your code, these are grouped into commits. To make a commit, you first must 
can 'add' all the changes you have made. You can do this using the command `git add [file]` to add any
specific file, or you can use the command `git add -u` to add all changes to existing files. 
You can use the command `git status` to see what files have been changed, and which ones are added 
(the ones you have added will be green). You can also view the changes themselves using the command
`git diff HEAD [file]`, which will show the changes you have made to a specific file (green is lines
you have added, red is lines you have deleted)

Once you have added your changes, you can commit them, using the command 
`git commit -m "[commit message]"`, where the commit message is a short summary of the changes made in
the commit. It is useful to commit often, since the commits serve as backups for your code, and smaller
commits with a clear purpose are easier to understand.

Synchronizing your Changes
--------------------------

Finally, once you have made your commit, you will need to share it with everyone else. This can be done
using the command `git push`. You may be asked for some login details here, these are the same as the 
ones you need to log into gitlab/github/whatever.
 
In order to get other people's commits, e.g. getting the changes that were made to your branch when it
was merged into master, you need to use the command `git pull`. This will update the current branch to
the latest version!

