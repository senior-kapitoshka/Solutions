#define ARRAY_LENGTH(a) (sizeof(a)/sizeof(*a))
///////////
#define ARRAY_LENGTH(a) (int)(sizeof(a)/sizeof((a)[0]))