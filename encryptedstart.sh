user=`whoami`
userhome=$HOME

#echo $user
#echo $userhome

if [ -d $userhome/.config/PEM ]; then
	echo "PEM directory exists"
else		
	echo "PEM directory does not exist"
	mkdir $userhome/.config/PEM
fi	
if [ -d $userhome/.config/PEM/keys ]; then
	echo "Key directory exists"
else
	echo Key directory does not exist
	mkdir $userhome/.config/PEM/keys
fi	
if [ -d $userhome/.config/PEM/passwords ]; then
	echo "Password directory exists"
else
	echo "Password directory does not exist"
	mkdir $userhome/.config/PEM/passwords
fi	
if [ -d $userhome/.config/PEM/settings ]; then
	echo "Setting directory exists"
else
	echo "Setting directory does not exist"
	mkdir $userhome/.config/PEM/settings
fi	

rootprojectdirectory=$userhome/.config/PEM
keydirectory=$rootprojectdirectory/keys
passworddirectory=$rootprojectdirectory/passwords
settingdirectory=$rootprojectdirectory/settings

#echo $rootprojectdirectory
#echo $keydirectory
#echo $passworddirectory
#echo $settingdirectory
echo ""

/usr/bin/PasswordEncryption $rootprojectdirectory
