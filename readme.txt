This is just so the repo isn't empty
1. git clone https://github.com/paydrone/CIS3250.git
2. go into the folder
3. git pull origin
4. use git add <filename> or git add *
5. git commit -m "comment"
6. git push origin master
7. git status
8. git diff master
9. use git checkout -b newbranch      to make a new branch and switch to it automatically
10. use git chechout master           to just switch branches
11. use git branch -d oldbranch       to delete
12. use git push origin branchname    to make the branch up to git and not just local
13. use git pull                      to get the latest commit
14. use git merge branchname          to merge that branch with your current branch
15. use git tag -a tagname -m "tag message"    to make a tag
16. use git tag tagname branchcommitidname           to attach a tag to a branch commit
17. use git log                       for history
18. use git log --author=name         for a user's history
19. use git fetch origin
    git reset --hard origin/master    for a fresh install if you can't figure out how to merge and you are desperate
