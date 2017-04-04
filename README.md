# 1w-redis-ssdb
1w测点写入ssdb和redis数据刷新周期
hiredis-example: examples/example.c $(STLIBNAME)
	$(CC) -o examples/$@ $(REAL_CFLAGS) $(REAL_LDFLAGS) -I. $< $(STLIBNAME)
performance: examples/performance.cpp $(STLIBNAME)
	$(CXX) -o examples/$@ $(REAL_CFLAGS) $(REAL_LDFLAGS) -I. $< $(STLIBNAME)
examples: $(EXAMPLES)
