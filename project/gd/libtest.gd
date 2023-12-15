extends Node

var tran := Imgtran.new()

func _ready():
	var test_1 := tran.add(1, 2)
	print("Imgtran says: 1 + 2 = ", test_1)
	var test_2 := tran.square(2.1)
	print("Imgtran says: 2.1 ** 2 = ", test_2)

	var test_3 := tran.dct_2d([1.2, 3.4, 5.6, 7.8])
	print(test_3)

	var test_4 := tran.idct_2d(test_3)
	print(test_4)
