extends Node

var tran := Imgtran.new()

func _ready():
	var test_1 := tran.add(1, 2)
	print("Imgtran says: 1 + 2 = ", test_1)
	var test_2 := tran.addf(3.0, 2.5)
	print("Imgtran says: 3.0 + 2.5 = ", test_2)
	var test_3 := tran.square(2.1)
	print("Imgtran says: 2.1 ** 2 = ", test_3)
