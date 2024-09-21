//Kunal Agarwal MT2024083
/*15. Write a program to display the environmental variable of the user (use environ).*/


/* Environment variables are key-value pairs that are set in the operating system environment and can be accessed by programs running in that environment. */


#include <stdio.h>

extern char **environ;
/*The extern keyword indicates that the variable environ is defined elsewhere, possibly in another file or in the system libraries. It tells the compiler that the actual storage for environ is allocated somewhere else, and this declaration is simply informing the compiler about its existence so that it can be used in this file.*/
//environ is a pointer to an array of strings where each string represents an environment variable in the format KEY=VALUE
int main() {
    char **env = environ;
    /*the environ variable is automatically populated with the environment variables when a program starts. Each element of the environ array is a string that contains the name and value of an environment variable, such as PATH=/usr/bin, HOME=/home/username, etc.*/
    //env  holds the address of the first environment variable in the array.
    // Loop through the environment variables
    while (*env) {
        /*env points to an array of strings, *env is a pointer to a string, and when env reaches the end of the array, it will point to NULL.*/
        printf("%s\n", *env);
        /*nside the loop, *env is printed using the printf() function.*/
        env++;
        //This line increments the env pointer to point to the next string in the environment variable array.
    }  

    return 0;
}
 /*output:
 kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 15.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
MallocNanoZone=0
USER=kunalagarwal
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/homebrew/bin
LOGNAME=kunalagarwal
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.exgmuddqFx/Listeners
HOME=/Users/kunalagarwal
SHELL=/bin/zsh
TMPDIR=/var/folders/js/pysx198n77z6420t4yzz1n740000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
SHLVL=1
PWD=/Users/kunalagarwal/software systems handson 1
OLDPWD=/Users/kunalagarwal/software systems handson 1
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.92.2
LANG=en_US.UTF-8
COLORTERM=truecolor
GIT_ASKPASS=/private/var/folders/js/pysx198n77z6420t4yzz1n740000gn/T/AppTranslocation/7FB47571-783A-4D51-BE26-5E2442797209/d/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/private/var/folders/js/pysx198n77z6420t4yzz1n740000gn/T/AppTranslocation/7FB47571-783A-4D51-BE26-5E2442797209/d/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/private/var/folders/js/pysx198n77z6420t4yzz1n740000gn/T/AppTranslocation/7FB47571-783A-4D51-BE26-5E2442797209/d/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/js/pysx198n77z6420t4yzz1n740000gn/T/vscode-git-677b809c7d.sock
VSCODE_INJECTION=1
ZDOTDIR=/Users/kunalagarwal
USER_ZDOTDIR=/Users/kunalagarwal
TERM=xterm-256color
_=/Users/kunalagarwal/software systems handson 1/./a.out
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % */