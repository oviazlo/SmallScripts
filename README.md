# SmallScripts
script use three environment variables:
FILE - full name of input file
HIST - name of hist in the inpput root file
OUT - name of output file

example of usage:
FILE=/home/oviazlo/PhD_study/Wprime/CrossCheckWithMagnar_aug2016/files/Magnar/aug2016/mt_inputs_nosys.root  HIST=data OUT=magnar_data_mt_new.txt root -l getBinCounts.C
