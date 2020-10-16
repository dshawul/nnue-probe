# What is it

nnue-probe is library for probing NNUE neural networks for chess.
The core nnue probing code is taken from [CFish](https://github.com/syzygy1/Cfish)

# How to build

To compile

    make clean; make COMP=gcc 

Cross-compiling for windows and android from linux is possible by setting COMP=[win/arm]

# Probing from python

	from ctypes import *
	nnue = cdll.LoadLibrary("libnnueprobe.so")
	nnue.nnue_init("/home/daniel/Scorpio/nets-scorpio/nn-baeb9ef2d183.nnue")
	score = nnue.nnue_evaluate_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")
	print "Score = ", score

The result

	Loading NNUE : /home/daniel/Scorpio/nets-scorpio/nn-baeb9ef2d183.nnue
	NNUE loaded !
	Score =  42

