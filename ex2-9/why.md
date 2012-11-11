Let x be aaa...1... which the bits after the 1 shown are all 0's.

That is, x = aaaa...1 or aaa...10...

+ **Situation 1**: x = aaaa...1

	x-1 = aaaa...0

	x & (x-1) = aaaa...0, proved.

+ **Situation 2**: x = aaa...10...

	x-1 = aaa...01... (the bits before the original '01' not changed, but the bits after them changed to all 1's and they changed too)

	x & (x-1) = aaa...00... (the bits before the original '01' not changed, but the bits after them changed to all 0's), proved.

Summary: x&=(x-1) can delete the right most 1 in x's binary bits.