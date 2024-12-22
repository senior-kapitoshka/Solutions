static unsigned i=1;
unsigned get_number (void)
{
  unsigned db=i;
  i*=2;
  return db;
}

////////////
unsigned get_number (void)
{
  static int a = 0;
  return 1 << (a++);
}