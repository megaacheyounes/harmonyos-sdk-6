/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Guido van Rossum.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)glob.h	8.1 (Berkeley) 6/2/93
 * $FreeBSD$
 */

#ifndef _GLOB_H_
#define _GLOB_H_

#include <sys/cdefs.h>
#include <sys/types.h>

struct dirent;
struct stat;

typedef struct {
  size_t gl_pathc;
  size_t gl_matchc;
  size_t gl_offs;
  int gl_flags;
  char** gl_pathv;

  int (*gl_errfunc)(const char* __failure_path, int __failure_errno);

  void (*gl_closedir)(void*);
  struct dirent* (*gl_readdir)(void*);
  void* (*gl_opendir)(const char*);
  int (*gl_lstat)(const char*, struct stat*);
  int (*gl_stat)(const char*, struct stat*);
} glob_t;

#define GLOB_APPEND	0x0001
#define GLOB_DOOFFS	0x0002
#define GLOB_ERR	0x0004
#define GLOB_MARK	0x0008
#define GLOB_NOCHECK	0x0010
#define GLOB_NOSORT	0x0020
#define GLOB_NOESCAPE	0x2000

#define GLOB_NOSPACE	(-1)
#define GLOB_ABORTED	(-2)
#define GLOB_NOMATCH	(-3)

#if __USE_BSD
#define GLOB_ALTDIRFUNC	0x0040
#define GLOB_BRACE	0x0080
#define GLOB_MAGCHAR	0x0100
#define GLOB_NOMAGIC	0x0200
#define GLOB_QUOTE	0x0400
#define GLOB_TILDE	0x0800
#define GLOB_LIMIT	0x1000
#endif

__BEGIN_DECLS

int glob(const char* __pattern, int __flags, int (*__error_callback)(const char* __failure_path, int __failure_errno), glob_t* __result_ptr);
void globfree(glob_t* __result_ptr);

__END_DECLS

#endif
