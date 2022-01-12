#pragma once
#ifndef _FLUSHER
#define _FLUSHER

#ifdef WIN
#define printf(...) { printf(__VA_ARGS__); fflush(stdout); }
#endif

#endif