#!/bin/bash

for i in malware_src/*
do
	if test -f "$i" 
    then
       ./IAT_Patcher $i rep_list 
    fi
done

mv malware_src/*_new malware_dst/
