SET PATH=c:\Program Files (x86)\Microsoft Visual Studio 12.0\Team Tools\Performance Tools\
vsinstr @CommandOption.txt
vsperfcmd -start:coverage -output:CodeCoverageDemo.coverage
UT.exe
vsperfcmd -shutdown
echo Complete!
pause