set pm3d map

do for [ii=1:3:1] {
  file=sprintf('ergebnis%dA.dat',ii)

  resultName=sprintf('ergebnis%dA.jpg',ii)
  set term jpeg
  set output resultName

  spl file u 1:2:3 with image

  if (ii < 3) {
    file=sprintf('ergebnis%dB.dat',ii)

    resultName=sprintf('ergebnis%dB.jpg',ii)
    set term jpeg
    set output resultName

    plot file u 1:2:3 with image
  }
}
