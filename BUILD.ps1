if ($ARGS[ 0 ] -eq "clean")
{
    Remove-Item *.o, *.exe
    exit
}
make -f build.mk
if (($ARGS[ 0 ] -eq "run") -and $?)
{
    .\ATC.exe
}