#!/bin/bash
echo Generating .fnts...
../../font_generator/a.out
python ../scripts/font_converter.py default*.fnt
