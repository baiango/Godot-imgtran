! Fortran function to calculate the square of a number
function square(x) result(sq)
    real(8), intent(in) :: x
    real(8) :: sq

    sq = x ** 2
end function square
