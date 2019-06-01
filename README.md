auto_IAT patcher 
==========

CLI extension to IAT_Patcher by Hashier Zade<br/>
IAT_Patcher: http://hasherezade.github.io/IAT_patcher/<br/>

Requires:
+ bearparser: https://github.com/hasherezade/bearparser<br/>
+ Qt5 SDK<br/>
+ Qt5 Core<br/>
+ Qt5 GUI<br/>
+ cmake http://www.cmake.org/<br/>

Autobuild:
-
Make sure that Qt and cmake requirement are satisfied<br/>
Clone the repository<br/>
To build it on Linux or MacOS you can use the given script - autobuild.sh.
<pre>
git clone repo
cd auto_IAT_patcher
bash autobuild.sh
</pre>


To use it:
-

Put all your executables in build/patcher/malware_src<br/>
run build/patcher/hook_em.sh:<br/>
<pre>
cd build/patcher
bash hook_em.sh
</pre>
Find hooked executables in build/patcher/malware_dst


Configurations:
-

<b>1. Hook replacement declarations:</b>b><br/>

build/patcher/rep_list defines hook replacements
+ First line a number n, e.g. total number of hook declarations
+ n lines follows, each line is 4 tuple: original API, original dll, hooked API, hooked dll
