#Basic
git status #tells you about the current status
PS Update-Help #gets updated help files
PS Get-help <Function name> ex. Get-help Invoke-Object
PS start "<filepath> or <https string" # ex. PS start "https:/go.microsoft.com/fwlink/?LinkID=107116"


#Env Configuration
git config --global user.name "Michael Dixon"# sets your name for commits
git config --global user.email "131546168+Dixon211@users.noreply.github.com" #sets email for commits

#from local working dir to staging area to Repository
git add "File\path" #from local to staging area
git add . #adds all to git staging
git status #can now see the files in the staging area
git commit -m "Your Message Here!" #Send staging area to repo
git push $remotebranch $localbranch #Push code up to github stream

#Branches
git branch -v #view current branch
git branch -c "BranchName" #create new branch
git branch -d "BranchName" #delete named branch
git switch $branchname #switch to that branch

#Remote
git remote -v # view remote connections
git remote add $connectionname $githuburl
git remote remove $connectionname

#Push
git push --set-upstream $filename $branchname #set push and pull to pull from here
git push $remoteconnection --delete $remotebranch

#github connection, gh

###Encryption




https://github.com/Dixon211/Practice.git

function gitaddC($filepath){
    Write-Host "`nNeed to find"
}



$fp = "C:\\Github"