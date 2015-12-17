#!/bin/bash

for i in `ls -Sr input*.txt`; do ./a.out < "$i" ; done
