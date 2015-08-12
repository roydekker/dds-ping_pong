TARGET_PLATFORM=x86_64.linux

# Set the current working directory
sed -i "s|@@INSTALLDIR@@|$PWD|g" opensplice/${TARGET_PLATFORM}/release.com

#. $PWD/opensplice/${TARGET_PLATFORM}/release.com

