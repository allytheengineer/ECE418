/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */
extern unsigned int blockSize;
extern unsigned int numWords;
extern unsigned int wordSize;
extern signed int hash[8];
extern unsigned int a;
extern unsigned int b;
extern unsigned int c;
extern unsigned int d;
extern unsigned int e;
extern unsigned int f;
extern unsigned int g;
extern unsigned int h;
extern signed int constants[64];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int getStringLength( char *llvm_cbe_str);
 char *numToBinary(signed int llvm_cbe_num,  char *llvm_cbe_binaryBuffer, signed int llvm_cbe_buffer_size);
 char *charToBinary( char *llvm_cbe_input,  char *llvm_cbe_output);
void pad( char *llvm_cbe_binaryMessage, signed int llvm_cbe_sizeBits,  char (*llvm_cbe_messageBlocks)[513], signed int llvm_cbe_numBlocks);
void padv2( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[512]);
void padv3( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[512]);
signed int padv4( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[513]);
signed int binaryToInt( char *llvm_cbe_binaryString);
signed int rotateRightint(signed int llvm_cbe_x, signed int llvm_cbe_n);
void createMessageSchedule( char *llvm_cbe_messageBlock, signed int *llvm_cbe_messageSchedule);
signed int choice(signed int llvm_cbe_x, signed int llvm_cbe_y, signed int llvm_cbe_z);
signed int majority(signed int llvm_cbe_x, signed int llvm_cbe_y, signed int llvm_cbe_z);
void compression(signed int *llvm_cbe_messageSchedule);
void prep( char *llvm_cbe_message);
signed int main(void);


/* Global Variable Definitions and Initialization */
unsigned int blockSize = 512u;
unsigned int numWords = 16u;
unsigned int wordSize = 32u;
signed int hash[8] = { 1779033703u, 3144134277u, 1013904242u, 2773480762u, 1359893119u, 2600822924u, 528734635u, 1541459225u };
unsigned int a;
unsigned int g;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int e;
unsigned int f;
unsigned int h;
static  char aesl_internal__OC_str9[329] = "We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defense, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America.\x00";
signed int constants[64] = { 1116352408u, 1899447441u, 3049323471u, 3921009573u, 961987163u, 1508970993u, 2453635748u, 2870763221u, 3624381080u, 310598401u, 607225278u, 1426881987u, 1925078388u, 2162078206u, 2614888103u, 3248222580u, 3835390401u, 4022224774u, 264347078u, 604807628u, 770255983u, 1249150122u, 1555081692u, 1996064986u, 2554220882u, 2821834349u, 2952996808u, 3210313671u, 3336571891u, 3584528711u, 113926993u, 338241895u, 666307205u, 773529912u, 1294757372u, 1396182291u, 1695183700u, 1986661051u, 2177026350u, 2456956037u, 2730485921u, 2820302411u, 3259730800u, 3345764771u, 3516065817u, 3600352804u, 4094571909u, 275423344u, 430227734u, 506948616u, 659060556u, 883997877u, 958139571u, 1322822218u, 1537002063u, 1747873779u, 1955562222u, 2024104815u, 2227730452u, 2361852424u, 2428436474u, 2756734187u, 3204031479u, 3329325298u };
static  char aesl_internal__OC_str2[12] = "%s size: %d";
static  char aesl_internal__OC_str4[19] = "\n%X%X%X%X%X%X%X%X\n";
static  char aesl_internal__OC_str3[14] = "block: %d\n%s\n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int getStringLength( char *llvm_cbe_str) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  unsigned char llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__2;
  unsigned int llvm_cbe_tmp__2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned char llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getStringLength\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* %%str, align 1, !dbg !14 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__1 = (unsigned char )*llvm_cbe_str;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
  if (((llvm_cbe_tmp__1&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%8, %%.lr.ph ], [ 1, %%0  for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__7);
printf("\n = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ %%7, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__2 = (unsigned int )llvm_cbe_tmp__2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__2);
printf("\n = 0x%X",llvm_cbe_tmp__6);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__3 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%str, i64 %%4, !dbg !14 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__4 = ( char *)(&llvm_cbe_str[(((signed long long )llvm_cbe_tmp__3))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !14 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__5 = (unsigned char )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%3, 1, !dbg !15 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
  if (((llvm_cbe_tmp__5&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__7;   /* for PHI node */
    llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ 0, %%0 ], [ %%7, %%.lr.ph  for 0x%I64xth hint within @getStringLength  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getStringLength}\n");
  return llvm_cbe__2e_lcssa;
}


 char *numToBinary(signed int llvm_cbe_num,  char *llvm_cbe_binaryBuffer, signed int llvm_cbe_buffer_size) {
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_smax_count = 0;
  unsigned int llvm_cbe_smax;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__16;
  unsigned int llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
   char *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned char llvm_cbe_storemerge1;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec4_count = 0;
  unsigned long long llvm_cbe__2e_rec4;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_pn_count = 0;
  unsigned long long llvm_cbe__2e_pn;
  unsigned long long llvm_cbe__2e_pn__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
   char *llvm_cbe__2e_lcssa;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @numToBinary\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add nsw i32 %%buffer_size, -1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_buffer_size&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%1 to i64, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__9 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
  if ((((signed int )llvm_cbe_buffer_size) > ((signed int )4294967295u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%2, -1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = xor i32 %%buffer_size, -1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__11 = (unsigned int )llvm_cbe_buffer_size ^ 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%smax = select i1 %%6, i32 %%5, i32 - for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_smax_count);
  llvm_cbe_smax = (unsigned int )(((((signed int )llvm_cbe_tmp__11) > ((signed int )4294967295u))) ? ((unsigned int )llvm_cbe_tmp__11) : ((unsigned int )4294967295u));
if (AESL_DEBUG_TRACE)
printf("\nsmax = 0x%X\n", llvm_cbe_smax);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i32 %%smax, %%buffer_size, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_smax&4294967295ull)) + ((unsigned int )(llvm_cbe_buffer_size&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%7, 1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_tmp__12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i6 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__13&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub i64 %%4, %%9, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__15 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__15&18446744073709551615ull)));
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_buffer_size;   /* for PHI node */
  llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )llvm_cbe_num;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__21;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ %%buffer_size, %%.lr.ph ], [ %%17, %%11  for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\nbuffer_size = 0x%X",llvm_cbe_buffer_size);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i32 [ %%num, %%.lr.ph ], [ %%16, %%11  for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\nnum = 0x%X",llvm_cbe_num);
printf("\n = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.lr.ph ], [ %%.rec4, %%11  for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec4 = 0x%I64X",llvm_cbe__2e_rec4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%2, %%.re for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr i8* %%binaryBuffer, i64 %%.su for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__17 = ( char *)(&llvm_cbe_binaryBuffer[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = and i32 %%12, 1, !dbg !14 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__18 = (unsigned int )llvm_cbe_tmp__16 & 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = select i1 %%15, i8 48, i8 49, !dbg !14 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned char )((((llvm_cbe_tmp__18&4294967295U) == (0u&4294967295U))) ? ((unsigned char )((unsigned char )48)) : ((unsigned char )((unsigned char )49)));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1 = 0x%X\n", llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%storemerge1, i8* %%13, align 1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_58_count);
  *llvm_cbe_tmp__17 = llvm_cbe_storemerge1;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1 = 0x%X\n", llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec4 = add i64 %%.rec, -1, !dbg !16 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe__2e_rec4_count);
  llvm_cbe__2e_rec4 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec4 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = lshr i32 %%12, 1, !dbg !14 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge2, -1, !dbg !15 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge2) > ((signed int )0u))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec4;   /* for PHI node */
    goto llvm_cbe_tmp__21;
  } else {
    llvm_cbe__2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__15;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.pn = phi i64 [ %%2, %%0 ], [ %%10, %%11  for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe__2e_pn_count);
  llvm_cbe__2e_pn = (unsigned long long )llvm_cbe__2e_pn__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.pn = 0x%I64X",llvm_cbe__2e_pn);
printf("\n = 0x%I64X",llvm_cbe_tmp__9);
printf("\n = 0x%I64X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = getelementptr inbounds i8* %%binaryBuffer, i64 %%.pn, !dbg !16 for 0x%I64xth hint within @numToBinary  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = ( char *)(&llvm_cbe_binaryBuffer[(((signed long long )llvm_cbe__2e_pn))]);
if (AESL_DEBUG_TRACE) {
printf("\n.pn = 0x%I64X",((signed long long )llvm_cbe__2e_pn));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @numToBinary}\n");
  return llvm_cbe__2e_lcssa;
}


 char *charToBinary( char *llvm_cbe_input,  char *llvm_cbe_output) {
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
   char *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
   char *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__29;
  unsigned int llvm_cbe_tmp__29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned char llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned char llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned char llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
   char *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned char llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
   char *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
   char *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned char llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned char llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
   char *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned char llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
   char *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @charToBinary\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @getStringLength(i8* %%input), !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__22 = (unsigned int )getStringLength(( char *)llvm_cbe_input);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl nsw i32 %%1, 3, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_tmp__22 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__24 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%output, i64 %%3, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__25 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__24))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__24));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_86_count);
  *llvm_cbe_tmp__25 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @getStringLength(i8* %%input), !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__26 = (unsigned int )getStringLength(( char *)llvm_cbe_input);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__26);
}
  if ((((signed int )llvm_cbe_tmp__26) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 8, !dbg !16 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__27 = ( char *)(&llvm_cbe_temp[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__29__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__76;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%.lr.ph ], [ %%55, %%9  for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i32 [ 0, %%.lr.ph ], [ %%16, %%9  for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__29 = (unsigned int )llvm_cbe_tmp__29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__35);
}

#ifdef AESL_BC_SIM
  assert(((signed long long )8ull) < 9 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%7, align 1, !dbg !16 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_99_count);
  *llvm_cbe_tmp__27 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge3 to i64, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__30 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%input, i64 %%11, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__31 = ( char *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__30))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__30));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__32 = (unsigned char )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i8 %%13 to i32, !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__33 = (unsigned int )((signed int )( char )llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i8* @numToBinary(i32 %%14, i8* %%8, i32 8), !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_104_count);
  ( char *)numToBinary(llvm_cbe_tmp__33, ( char *)llvm_cbe_tmp__28, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__33);
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%10, 8, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_tmp__29&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8* %%8, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__36 = (unsigned char )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%10 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__37 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%output, i64 %%18, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__37))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* %%19, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_114_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = or i32 %%10, 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__39 = (unsigned int )llvm_cbe_tmp__29 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_temp[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__41 = (unsigned char )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%20 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__42 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%output, i64 %%23, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__43 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%22, i8* %%24, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_126_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%20, 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__39&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 2, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__45 = ( char *)(&llvm_cbe_temp[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__46 = (unsigned char )*llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%25 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%output, i64 %%28, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__48 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__47))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__47));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%27, i8* %%29, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_138_count);
  *llvm_cbe_tmp__48 = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = or i32 %%10, 3, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__49 = (unsigned int )llvm_cbe_tmp__29 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 3, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_temp[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i8* %%31, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%30 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__52 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%output, i64 %%33, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__53 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__52))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__52));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%32, i8* %%34, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_150_count);
  *llvm_cbe_tmp__53 = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%30, 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_tmp__49&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 4, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__55 = ( char *)(&llvm_cbe_temp[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i8* %%36, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__56 = (unsigned char )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i32 %%35 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__57 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%output, i64 %%38, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__58 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%37, i8* %%39, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_162_count);
  *llvm_cbe_tmp__58 = llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%30, 2, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_tmp__49&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 5, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__60 = ( char *)(&llvm_cbe_temp[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__61 = (unsigned char )*llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%40 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__62 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8* %%output, i64 %%43, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__63 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__62))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__62));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%44, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_174_count);
  *llvm_cbe_tmp__63 = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%30, 3, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__49&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 6, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_temp[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8* %%46, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__66 = (unsigned char )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = sext i32 %%45 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__67 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%output, i64 %%48, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__68 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__67))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__67));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%47, i8* %%49, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_186_count);
  *llvm_cbe_tmp__68 = llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = or i32 %%10, 7, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__69 = (unsigned int )llvm_cbe_tmp__29 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [9 x i8]* %%temp, i64 0, i64 7, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__70 = ( char *)(&llvm_cbe_temp[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 9)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%51, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__71 = (unsigned char )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = sext i32 %%50 to i64, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__72 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds i8* %%output, i64 %%53, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__73 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%52, i8* %%54, align 1, !dbg !15 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_198_count);
  *llvm_cbe_tmp__73 = llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%storemerge3, 1, !dbg !16 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = call i32 @getStringLength(i8* %%input), !dbg !14 for 0x%I64xth hint within @charToBinary  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__75 = (unsigned int )getStringLength(( char *)llvm_cbe_input);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__75);
}
  if ((((signed int )llvm_cbe_tmp__74) < ((signed int )llvm_cbe_tmp__75))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
    llvm_cbe_tmp__29__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__35;   /* for PHI node */
    goto llvm_cbe_tmp__76;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @charToBinary}\n");
  return llvm_cbe_output;
}


void pad( char *llvm_cbe_binaryMessage, signed int llvm_cbe_sizeBits,  char (*llvm_cbe_messageBlocks)[513], signed int llvm_cbe_numBlocks) {
  static  unsigned long long aesl_llvm_cbe_messageLengthInBinary_count = 0;
   char llvm_cbe_messageLengthInBinary[65];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_indvar_count = 0;
  unsigned int llvm_cbe_indvar;
  unsigned int llvm_cbe_indvar__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned int llvm_cbe__2e_in;
  unsigned int llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_indvar_2e_next_count = 0;
  unsigned int llvm_cbe_indvar_2e_next;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
   char *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
   char *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge110_count = 0;
  unsigned int llvm_cbe_storemerge110;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_scevgep_count = 0;
   char *llvm_cbe_scevgep;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
   char *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
   char *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
   char *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
   char *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned int llvm_cbe_storemerge29;
  unsigned int llvm_cbe_storemerge29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
   char *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  unsigned char llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
   char *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond19_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge38_count = 0;
  unsigned int llvm_cbe_storemerge38;
  unsigned int llvm_cbe_storemerge38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  unsigned int llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge46_count = 0;
  unsigned int llvm_cbe_storemerge46;
  unsigned int llvm_cbe_storemerge46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
   char *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned char llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
   char *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned int llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar5_count = 0;
  unsigned int llvm_cbe_putchar5;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pad\n");
  llvm_cbe_indvar__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_sizeBits;   /* for PHI node */
  goto llvm_cbe_tmp__115;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%indvar = phi i32 [ %%indvar.next, %%1 ], [ 0, %%0  for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_indvar_count);
  llvm_cbe_indvar = (unsigned int )llvm_cbe_indvar__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nindvar = 0x%X",llvm_cbe_indvar);
printf("\nindvar.next = 0x%X",llvm_cbe_indvar_2e_next);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i32 [ %%2, %%1 ], [ %%sizeBits, %%0  for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned int )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%X",llvm_cbe__2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__77);
printf("\nsizeBits = 0x%X",llvm_cbe_sizeBits);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%.in, 1, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__77 = (unsigned int )((unsigned int )(llvm_cbe__2e_in&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__77&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = srem i32 %%2, 512, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__78 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__77) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  %%indvar.next = add i32 %%indvar, 1, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_indvar_2e_next_count);
  llvm_cbe_indvar_2e_next = (unsigned int )((unsigned int )(llvm_cbe_indvar&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nindvar.next = 0x%X\n", ((unsigned int )(llvm_cbe_indvar_2e_next&4294967295ull)));
  if (((llvm_cbe_tmp__78&4294967295U) == (448u&4294967295U))) {
    goto llvm_cbe_tmp__116;
  } else {
    llvm_cbe_indvar__PHI_TEMPORARY = (unsigned int )llvm_cbe_indvar_2e_next;   /* for PHI node */
    llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__77;   /* for PHI node */
    goto llvm_cbe_tmp__115;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%.in, 65, !dbg !18 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(llvm_cbe__2e_in&4294967295ull)) + ((unsigned int )(65u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__79&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%6 to i64, !dbg !18 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__80 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__79&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = alloca i8, i64 %%7, align 16, !dbg !18 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__81 = ( char *)( char *) alloca(sizeof(unsigned char ) * llvm_cbe_tmp__80);
  if ((((signed int )llvm_cbe_sizeBits) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph16;
  } else {
    goto llvm_cbe_tmp__117;
  }

llvm_cbe__2e_lr_2e_ph16:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%sizeBits, -1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__82 = (unsigned int )((unsigned int )(llvm_cbe_sizeBits&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__82&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i6 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__83 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__82&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%11, 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__84 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__83&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i8* @memcpy(i8* %%8, i8* %%binaryMessage, i64 %%12 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_266_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__81, ( char *)llvm_cbe_binaryMessage, llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__84);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__85);
}
  goto llvm_cbe_tmp__117;

llvm_cbe_tmp__117:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%sizeBits to i64, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__86 = (unsigned long long )((signed long long )(signed int )llvm_cbe_sizeBits);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%8, i64 %%15, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__87 = ( char *)(&llvm_cbe_tmp__81[(((signed long long )llvm_cbe_tmp__86))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__86));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 49, i8* %%16, align 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_270_count);
  *llvm_cbe_tmp__87 = ((unsigned char )49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )49));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge110 = add nsw i32 %%sizeBits, 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_storemerge110_count);
  llvm_cbe_storemerge110 = (unsigned int )((unsigned int )(llvm_cbe_sizeBits&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge110 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge110&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge110) < ((signed int )llvm_cbe_tmp__77))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__118;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%storemerge110 to i6 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__88 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge110);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%scevgep = getelementptr i8* %%8, i64 %%1 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_scevgep_count);
  llvm_cbe_scevgep = ( char *)(&llvm_cbe_tmp__81[(((signed long long )llvm_cbe_tmp__88))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__88));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%indvar, -1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__89 = (unsigned int )((unsigned int )(llvm_cbe_indvar&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__89&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%19 to i6 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__90 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__89&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i64 %%20, 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i8* @memset(i8* %%scevgep, i32 48, i64 %%21 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_289_count);
  ( char *)memset(( char *)llvm_cbe_scevgep, 48u, llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",48u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__91);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__92);
}
  goto llvm_cbe_tmp__118;

llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 64, !dbg !19 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__93 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )64ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )64ull) < 65 && "Write access out of array 'messageLengthInBinary' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%24, align 16, !dbg !19 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_294_count);
  *llvm_cbe_tmp__93 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__94 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i8* @numToBinary(i32 %%sizeBits, i8* %%25, i32 64), !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_296_count);
  ( char *)numToBinary(llvm_cbe_sizeBits, ( char *)llvm_cbe_tmp__94, 64u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument sizeBits = 0x%X",llvm_cbe_sizeBits);
printf("\nArgument  = 0x%X",64u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__95);
}
  llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__119;

llvm_cbe__2e_preheader7:
  if ((((signed int )llvm_cbe_numBlocks) > ((signed int )0u))) {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i32 [ 0, %%23 ], [ %%35, %%28  for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned int )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%X",llvm_cbe_storemerge29);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__102);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%storemerge29 to i64, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__96 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge29);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 %%29, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__97 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )llvm_cbe_tmp__96))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__96));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__96) < 65)) fprintf(stderr, "%s:%d: warning: Read access out of array 'messageLengthInBinary' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__98 = (unsigned char )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge29, %%2, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__99 = (unsigned int )((unsigned int )(llvm_cbe_storemerge29&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__77&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__99&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__100 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%8, i64 %%33, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__101 = ( char *)(&llvm_cbe_tmp__81[(((signed long long )llvm_cbe_tmp__100))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__100));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%31, i8* %%34, align 1, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_324_count);
  *llvm_cbe_tmp__101 = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%storemerge29, 1, !dbg !17 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__102 = (unsigned int )((unsigned int )(llvm_cbe_storemerge29&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__102&4294967295ull)));
  if (((llvm_cbe_tmp__102&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe__2e_preheader7;
  } else {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__102;   /* for PHI node */
    goto llvm_cbe_tmp__119;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge38 = phi i32 [ %%49, %%47 ], [ 0, %%.preheader7  for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_storemerge38_count);
  llvm_cbe_storemerge38 = (unsigned int )llvm_cbe_storemerge38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge38 = 0x%X",llvm_cbe_storemerge38);
printf("\n = 0x%X",llvm_cbe_tmp__114);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = shl i32 %%storemerge38, 9, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__103 = (unsigned int )llvm_cbe_storemerge38 << 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%storemerge38 to i64, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__104 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge38);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
  llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__120;

llvm_cbe_tmp__121:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar5 = call i32 @putchar(i32 10) nounwind, !dbg !20 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_putchar5_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar5 = 0x%X",llvm_cbe_putchar5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%37, i64 512, !dbg !16 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__104))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )512ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )512ull) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%48, align 1, !dbg !16 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_364_count);
  *llvm_cbe_tmp__113 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge38, 1, !dbg !19 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__114 = (unsigned int )((unsigned int )(llvm_cbe_storemerge38&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__114&4294967295ull)));
  if (((llvm_cbe_tmp__114&4294967295U) == (llvm_cbe_numBlocks&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__114;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge46 = phi i32 [ 0, %%.preheader ], [ %%46, %%38  for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_storemerge46_count);
  llvm_cbe_storemerge46 = (unsigned int )llvm_cbe_storemerge46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge46 = 0x%X",llvm_cbe_storemerge46);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__112);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add nsw i32 %%storemerge46, %%36, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__105 = (unsigned int )((unsigned int )(llvm_cbe_storemerge46&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__103&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__105&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%39 to i64, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__106 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i8* %%8, i64 %%40, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__107 = ( char *)(&llvm_cbe_tmp__81[(((signed long long )llvm_cbe_tmp__106))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__106));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__108 = (unsigned char )*llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%storemerge46 to i64, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__109 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%37, i64 %%43, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__110 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__104))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )llvm_cbe_tmp__109))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__109) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%44, align 1, !dbg !15 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_353_count);
  *llvm_cbe_tmp__110 = llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = sext i8 %%42 to i32, !dbg !19 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__111 = (unsigned int )((signed int )( char )llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 %%45) nounwind, !dbg !19 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__111);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%storemerge46, 1, !dbg !20 for 0x%I64xth hint within @pad  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__112 = (unsigned int )((unsigned int )(llvm_cbe_storemerge46&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__112&4294967295ull)));
  if (((llvm_cbe_tmp__112&4294967295U) == (512u&4294967295U))) {
    goto llvm_cbe_tmp__121;
  } else {
    llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__112;   /* for PHI node */
    goto llvm_cbe_tmp__120;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pad}\n");
  return;
}


void padv2( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[512]) {
  static  unsigned long long aesl_llvm_cbe_messageLengthInBinary_count = 0;
   char llvm_cbe_messageLengthInBinary[65];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  unsigned int llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  unsigned char llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
   char *llvm_cbe_tmp__129;
   char *llvm_cbe_tmp__129__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  unsigned int llvm_cbe_tmp__130;
  unsigned int llvm_cbe_tmp__130__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge149_count = 0;
  unsigned int llvm_cbe_storemerge149;
  unsigned int llvm_cbe_storemerge149__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  unsigned char llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned long long llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
   char *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
   char *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned char llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge14_2e_lcssa;
  unsigned int llvm_cbe_storemerge14_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
   char *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge18_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge18_2e_in;
  unsigned int llvm_cbe_storemerge18_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge18_count = 0;
  unsigned int llvm_cbe_storemerge18;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
   char *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
   char *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge26_count = 0;
  unsigned int llvm_cbe_storemerge26;
  unsigned int llvm_cbe_storemerge26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  unsigned char llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
   char *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  unsigned int llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
   char *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  unsigned int llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
   char *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  unsigned int llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padv2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__122 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__122);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__122;   /* for PHI node */
  goto llvm_cbe_tmp__163;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__163:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ %%1, %%0 ], [ %%6, %%2  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__122);
printf("\n = 0x%X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge, 64, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_400_count);
  llvm_cbe_tmp__123 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(64u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__123&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = and i32 %%3, 511, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__124 = (unsigned int )llvm_cbe_tmp__123 & 511u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge, 1, !dbg !17 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__125 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__125&4294967295ull)));
  if (((llvm_cbe_tmp__124&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__164;
  } else {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__125;   /* for PHI node */
    goto llvm_cbe_tmp__163;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__164:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__126 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* %%message, i32 %%8) nounwind, !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_418_count);
  printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), ( char *)llvm_cbe_message, llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__126);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%message, align 1, !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__128 = (unsigned char )*llvm_cbe_message;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__128);
  if (((llvm_cbe_tmp__128&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_storemerge14_2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge12;
  } else {
    llvm_cbe_tmp__129__PHI_TEMPORARY = ( char *)llvm_cbe_message;   /* for PHI node */
    llvm_cbe_tmp__130__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_storemerge149__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph11;
  }

  do {     /* Syntactic loop '.lr.ph11' to make GCC happy */
llvm_cbe__2e_lr_2e_ph11:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i8* [ %%23, %%.lr.ph11 ], [ %%message, %%7  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_422_count);
  llvm_cbe_tmp__129 = ( char *)llvm_cbe_tmp__129__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%., %%.lr.ph11 ], [ 0, %%7  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__130 = (unsigned int )llvm_cbe_tmp__130__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__130);
printf("\n. = 0x%X",llvm_cbe__2e_);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge149 = phi i32 [ %%21, %%.lr.ph11 ], [ 0, %%7  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge149_count);
  llvm_cbe_storemerge149 = (unsigned int )llvm_cbe_storemerge149__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge149 = 0x%X",llvm_cbe_storemerge149);
printf("\n = 0x%X",llvm_cbe_tmp__137);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%13, 1, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_425_count);
  llvm_cbe_tmp__131 = (unsigned int )((unsigned int )(llvm_cbe_tmp__130&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__131&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%14, i32 %%15, i32 %%13, !dbg !17 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_storemerge149&4294967295U) == (512u&4294967295U))) ? ((unsigned int )llvm_cbe_tmp__131) : ((unsigned int )llvm_cbe_tmp__130));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%12, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__132 = (unsigned char )*llvm_cbe_tmp__129;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = srem i32 %%storemerge149, 512, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__133 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge149) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__133));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%17 to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__134 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%. to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__135 = (unsigned long long )((signed long long )(signed int )llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%19, i64 %%18, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__136 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__135))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__134))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__135));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__134));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__134) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%20, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_437_count);
  *llvm_cbe_tmp__136 = llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%storemerge149, 1, !dbg !17 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__137 = (unsigned int )((unsigned int )(llvm_cbe_storemerge149&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__137&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%21 to i64, !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__138 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8* %%message, i64 %%22, !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__139 = ( char *)(&llvm_cbe_message[(((signed long long )llvm_cbe_tmp__138))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 1, !dbg !14 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__140 = (unsigned char )*llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
  if (((llvm_cbe_tmp__140&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    llvm_cbe_storemerge14_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__137;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge12;
  } else {
    llvm_cbe_tmp__129__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__139;   /* for PHI node */
    llvm_cbe_tmp__130__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    llvm_cbe_storemerge149__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__137;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph11;
  }

  } while (1); /* end of syntactic loop '.lr.ph11' */
llvm_cbe__2e__crit_edge12:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ 0, %%7 ], [ %%., %%.lr.ph11  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.lcssa = phi i32 [ 0, %%7 ], [ %%21, %%.lr.ph11  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge14_2e_lcssa_count);
  llvm_cbe_storemerge14_2e_lcssa = (unsigned int )llvm_cbe_storemerge14_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.lcssa = 0x%X",llvm_cbe_storemerge14_2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__137);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 @getStringLength(i8* %%message), !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__141 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__141);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%26 to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__142 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%.lcssa to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__143 = (unsigned long long )((signed long long )(signed int )llvm_cbe__2e_lcssa);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%28, i64 %%27, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__144 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__143))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__142))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__143));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__142));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__142) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 49, i8* %%29, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_459_count);
  *llvm_cbe_tmp__144 = ((unsigned char )49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )49));
  if (((llvm_cbe_storemerge14_2e_lcssa&4294967295U) == (447u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge18_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge14_2e_lcssa;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18.in = phi i32 [ %%storemerge18, %%.lr.ph ], [ %%storemerge14.lcssa, %%._crit_edge12  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge18_2e_in_count);
  llvm_cbe_storemerge18_2e_in = (unsigned int )llvm_cbe_storemerge18_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge18.in = 0x%X",llvm_cbe_storemerge18_2e_in);
printf("\nstoremerge18 = 0x%X",llvm_cbe_storemerge18);
printf("\nstoremerge14.lcssa = 0x%X",llvm_cbe_storemerge14_2e_lcssa);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18 = add nsw i32 %%storemerge18.in, 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge18_count);
  llvm_cbe_storemerge18 = (unsigned int )((unsigned int )(llvm_cbe_storemerge18_2e_in&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge18 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = srem i32 %%storemerge18, 512, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_462_count);
  llvm_cbe_tmp__145 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge18) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__145));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sext i32 %%31 to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__146 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%28, i64 %%32, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__147 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__143))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__146))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__143));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__146));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__146) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 48, i8* %%33, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_465_count);
  *llvm_cbe_tmp__147 = ((unsigned char )48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )48));
  if (((llvm_cbe_storemerge18&4294967295U) == (447u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge18_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge18;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 64, !dbg !18 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )64ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )64ull) < 65 && "Write access out of array 'messageLengthInBinary' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%35, align 16, !dbg !18 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_470_count);
  *llvm_cbe_tmp__148 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i32 @getStringLength(i8* %%message), !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_471_count);
  llvm_cbe_tmp__149 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__149);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__150 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = call i8* @numToBinary(i32 %%36, i8* %%37, i32 64), !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_473_count);
  ( char *)numToBinary(llvm_cbe_tmp__149, ( char *)llvm_cbe_tmp__150, 64u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__149);
printf("\nArgument  = 0x%X",64u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__151);
}
  llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__165;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge26 = phi i32 [ 0, %%._crit_edge ], [ %%46, %%39  for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_storemerge26_count);
  llvm_cbe_storemerge26 = (unsigned int )llvm_cbe_storemerge26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge26 = 0x%X",llvm_cbe_storemerge26);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__158);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%storemerge26 to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__152 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 %%40, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )llvm_cbe_tmp__152))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__152));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__152) < 65)) fprintf(stderr, "%s:%d: warning: Read access out of array 'messageLengthInBinary' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__154 = (unsigned char )*llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%storemerge26, 447, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__155 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(447u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__155&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__156 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%28, i64 %%44, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__157 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__143))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__156))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__143));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__156));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__156) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%45, align 1, !dbg !15 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_486_count);
  *llvm_cbe_tmp__157 = llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%storemerge26, 1, !dbg !18 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__158 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__158&4294967295ull)));
  if (((llvm_cbe_tmp__158&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__166;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__158;   /* for PHI node */
    goto llvm_cbe_tmp__165;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 10) nounwind, !dbg !19 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__159 = ( char *)(&(*llvm_cbe_messageBlocks)[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 0, i8* %%48) nounwind, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_501_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), 0u, ( char *)llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__160);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 1, i64 0, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__161 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 1, i8* %%50) nounwind, !dbg !16 for 0x%I64xth hint within @padv2  --> \n", ++aesl_llvm_cbe_508_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), 1u, ( char *)llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__162);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padv2}\n");
  return;
}


void padv3( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[512]) {
  static  unsigned long long aesl_llvm_cbe_messageLengthInBinary_count = 0;
   char llvm_cbe_messageLengthInBinary[65];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  unsigned int llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge_2e_in;
  unsigned int llvm_cbe_storemerge_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  unsigned int llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
   char *llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge18_count = 0;
  unsigned int llvm_cbe_storemerge18;
  unsigned int llvm_cbe_storemerge18__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned int llvm_cbe_tmp__172;
  unsigned int llvm_cbe_tmp__172__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge37_2e_us;
  unsigned int llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned int llvm_cbe_tmp__174;
  unsigned int llvm_cbe_tmp__174__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  unsigned int llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned int llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
   char *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  unsigned long long llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
   char *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  unsigned char llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
   char *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  unsigned long long llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
   char *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  unsigned int llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
   char *llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge46_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge46_2e_us;
  unsigned int llvm_cbe_storemerge46_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
   char *llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  unsigned char llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  unsigned int llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
   char *llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  unsigned int llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_count = 0;
  unsigned int llvm_cbe_storemerge37;
  unsigned int llvm_cbe_storemerge37__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  unsigned int llvm_cbe_tmp__196;
  unsigned int llvm_cbe_tmp__196__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  unsigned int llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  unsigned long long llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
   char *llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  unsigned long long llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
   char *llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  unsigned char llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  unsigned long long llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
   char *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
   char *llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  unsigned int llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  unsigned int llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond12_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond13_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
   char *llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  unsigned int llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
   char *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned int llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padv3\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_528_count);
  llvm_cbe_tmp__167 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__167);
}
  llvm_cbe_storemerge_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__167;   /* for PHI node */
  goto llvm_cbe_tmp__214;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__214:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.in = phi i32 [ %%1, %%0 ], [ %%storemerge, %%2  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge_2e_in_count);
  llvm_cbe_storemerge_2e_in = (unsigned int )llvm_cbe_storemerge_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge.in = 0x%X",llvm_cbe_storemerge_2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__167);
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = add nsw i32 %%storemerge.in, 1, !dbg !14 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )((unsigned int )(llvm_cbe_storemerge_2e_in&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = srem i32 %%storemerge, 512, !dbg !17 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__168 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__168));
  if (((llvm_cbe_tmp__168&4294967295U) == (448u&4294967295U))) {
    goto llvm_cbe_tmp__215;
  } else {
    llvm_cbe_storemerge_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge;   /* for PHI node */
    goto llvm_cbe_tmp__214;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__215:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sdiv i32 %%storemerge, 512, !dbg !17 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__169 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge) / ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__169));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%6, 1, !dbg !17 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_541_count);
  llvm_cbe_tmp__170 = (unsigned int )((unsigned int )(llvm_cbe_tmp__169&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__170&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__170) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__171 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__172__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%74, %%.us-lcssa.us  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge18_count);
  llvm_cbe_storemerge18 = (unsigned int )llvm_cbe_storemerge18__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge18 = 0x%X",llvm_cbe_storemerge18);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%.lcssa, %%.us-lcssa.us  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__172 = (unsigned int )llvm_cbe_tmp__172__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__172);
printf("\n = 0x%X",0u);
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge18 to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__173 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
  if (((llvm_cbe_storemerge18&4294967295U) == (llvm_cbe_tmp__169&4294967295U))) {
    llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__174__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_split_2e_us;
  } else {
    llvm_cbe_storemerge37__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__196__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;
  }

llvm_cbe__2e_us_2d_lcssa_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = add i32 %%10, 512, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )((unsigned int )(llvm_cbe_tmp__172&4294967295ull)) + ((unsigned int )(512u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n.lcssa = 0x%X\n", ((unsigned int )(llvm_cbe__2e_lcssa&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = add nsw i32 %%storemerge18, 1, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_682_count);
  llvm_cbe_tmp__209 = (unsigned int )((unsigned int )(llvm_cbe_storemerge18&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__209&4294967295ull)));
  if (((llvm_cbe_tmp__209&4294967295U) == (llvm_cbe_tmp__170&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__209;   /* for PHI node */
    llvm_cbe_tmp__172__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader.split.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37.us = phi i32 [ %%16, %%.loopexit.us ], [ 0, %%.preheader  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge37_2e_us_count);
  llvm_cbe_storemerge37_2e_us = (unsigned int )llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37.us = 0x%X",llvm_cbe_storemerge37_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__176);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%15, %%.loopexit.us ], [ %%10, %%.preheader  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__174 = (unsigned int )llvm_cbe_tmp__174__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__174);
printf("\n = 0x%X",llvm_cbe_tmp__175);
printf("\n = 0x%X",llvm_cbe_tmp__172);
}
  if (((llvm_cbe_tmp__174&4294967295U) == (447u&4294967295U))) {
    goto llvm_cbe_tmp__216;
  } else {
    goto llvm_cbe_tmp__217;
  }

llvm_cbe__2e_loopexit_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%13, 1, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__175 = (unsigned int )((unsigned int )(llvm_cbe_tmp__174&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__175&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge37.us, 1, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__176 = (unsigned int )((unsigned int )(llvm_cbe_storemerge37_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__176&4294967295ull)));
  if (((llvm_cbe_tmp__176&4294967295U) == (512u&4294967295U))) {
    goto llvm_cbe__2e_us_2d_lcssa_2e_us;
  } else {
    llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe_tmp__174__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__175;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_split_2e_us;
  }

llvm_cbe_tmp__218:
  goto llvm_cbe__2e_loopexit_2e_us;

llvm_cbe_tmp__219:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%storemerge37.us to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_594_count);
  llvm_cbe_tmp__177 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%19, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_595_count);
  llvm_cbe_tmp__178 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__177))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__177));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__177) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 49, i8* %%20, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_596_count);
  *llvm_cbe_tmp__178 = ((unsigned char )49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )49));
  goto llvm_cbe_tmp__218;

llvm_cbe_tmp__217:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32 @getStringLength(i8* %%message), !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__179 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__179);
}
  if (((llvm_cbe_tmp__174&4294967295U) == (llvm_cbe_tmp__179&4294967295U))) {
    goto llvm_cbe_tmp__219;
  } else {
    goto llvm_cbe_tmp__220;
  }

llvm_cbe_tmp__221:
  goto llvm_cbe_tmp__218;

llvm_cbe_tmp__222:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%13 to i64, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__180 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__174);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%message, i64 %%26, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__181 = ( char *)(&llvm_cbe_message[(((signed long long )llvm_cbe_tmp__180))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__180));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i8* %%27, align 1, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__182 = (unsigned char )*llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%storemerge37.us to i64, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_605_count);
  llvm_cbe_tmp__183 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%29, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_606_count);
  llvm_cbe_tmp__184 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__183))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__183) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%30, align 1, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_607_count);
  *llvm_cbe_tmp__184 = llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
  goto llvm_cbe_tmp__221;

llvm_cbe_tmp__220:
  if ((((signed int )llvm_cbe_tmp__174) < ((signed int )llvm_cbe_tmp__179))) {
    goto llvm_cbe_tmp__222;
  } else {
    goto llvm_cbe_tmp__223;
  }

llvm_cbe_tmp__224:
  goto llvm_cbe_tmp__221;

llvm_cbe_tmp__223:
  if ((((signed int )llvm_cbe_tmp__174) > ((signed int )llvm_cbe_tmp__179))) {
    goto llvm_cbe_tmp__225;
  } else {
    goto llvm_cbe_tmp__224;
  }

llvm_cbe_tmp__225:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%storemerge37.us to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_614_count);
  llvm_cbe_tmp__185 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%37, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__186 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__185))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__185));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__185) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 48, i8* %%38, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_616_count);
  *llvm_cbe_tmp__186 = ((unsigned char )48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )48));
  goto llvm_cbe_tmp__224;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__226:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge46.us = phi i32 [ 0, %%39 ], [ %%49, %%42  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge46_2e_us_count);
  llvm_cbe_storemerge46_2e_us = (unsigned int )llvm_cbe_storemerge46_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge46.us = 0x%X",llvm_cbe_storemerge46_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__195);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%storemerge46.us to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__189 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge46_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary, i64 0, i64 %%43, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__190 = ( char *)(&llvm_cbe_messageLengthInBinary[(((signed long long )llvm_cbe_tmp__189))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__189));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__189) < 65)) fprintf(stderr, "%s:%d: warning: Read access out of array 'messageLengthInBinary' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__191 = (unsigned char )*llvm_cbe_tmp__190;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%storemerge46.us, %%storemerge37.us, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__192 = (unsigned int )((unsigned int )(llvm_cbe_storemerge46_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge37_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__192&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = sext i32 %%46 to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__193 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%47, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__194 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__193))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__193));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__193) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%45, i8* %%48, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_632_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge46.us, 1, !dbg !19 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_633_count);
  llvm_cbe_tmp__195 = (unsigned int )((unsigned int )(llvm_cbe_storemerge46_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__195&4294967295ull)));
  if (((llvm_cbe_tmp__195&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe__2e_loopexit_2e_us;
  } else {
    llvm_cbe_storemerge46_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__195;   /* for PHI node */
    goto llvm_cbe_tmp__226;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__216:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__187 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__187);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i8* @numToBinary(i32 %%40, i8* %%9, i32 64), !dbg !14 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_619_count);
  ( char *)numToBinary(llvm_cbe_tmp__187, ( char *)llvm_cbe_tmp__171, 64u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__187);
printf("\nArgument  = 0x%X",64u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__188);
}
  llvm_cbe_storemerge46_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__226;

  } while (1); /* end of syntactic loop '.preheader.split.us' */
  do {     /* Syntactic loop '.preheader..preheader.split_crit_edge' to make GCC happy */
llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37 = phi i32 [ %%73, %%71 ], [ 0, %%.preheader  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_storemerge37_count);
  llvm_cbe_storemerge37 = (unsigned int )llvm_cbe_storemerge37__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37 = 0x%X",llvm_cbe_storemerge37);
printf("\n = 0x%X",llvm_cbe_tmp__208);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = phi i32 [ %%72, %%71 ], [ %%10, %%.preheader  for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_640_count);
  llvm_cbe_tmp__196 = (unsigned int )llvm_cbe_tmp__196__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__196);
printf("\n = 0x%X",llvm_cbe_tmp__207);
printf("\n = 0x%X",llvm_cbe_tmp__172);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i32 @getStringLength(i8* %%message), !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_641_count);
  llvm_cbe_tmp__197 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__197);
}
  if (((llvm_cbe_tmp__196&4294967295U) == (llvm_cbe_tmp__197&4294967295U))) {
    goto llvm_cbe_tmp__227;
  } else {
    goto llvm_cbe_tmp__228;
  }

llvm_cbe_tmp__229:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add nsw i32 %%50, 1, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__207 = (unsigned int )((unsigned int )(llvm_cbe_tmp__196&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__207&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add nsw i32 %%storemerge37, 1, !dbg !18 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__208 = (unsigned int )((unsigned int )(llvm_cbe_storemerge37&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__208&4294967295ull)));
  if (((llvm_cbe_tmp__208&4294967295U) == (512u&4294967295U))) {
    goto llvm_cbe__2e_us_2d_lcssa_2e_us;
  } else {
    llvm_cbe_storemerge37__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__208;   /* for PHI node */
    llvm_cbe_tmp__196__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__207;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;
  }

llvm_cbe_tmp__227:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = sext i32 %%storemerge37 to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_644_count);
  llvm_cbe_tmp__198 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__198);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%54, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__199 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__198))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__198));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__198) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 49, i8* %%55, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_646_count);
  *llvm_cbe_tmp__199 = ((unsigned char )49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )49));
  goto llvm_cbe_tmp__229;

llvm_cbe_tmp__230:
  goto llvm_cbe_tmp__229;

llvm_cbe_tmp__231:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = sext i32 %%50 to i64, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_650_count);
  llvm_cbe_tmp__200 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds i8* %%message, i64 %%59, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_651_count);
  llvm_cbe_tmp__201 = ( char *)(&llvm_cbe_message[(((signed long long )llvm_cbe_tmp__200))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__200));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i8* %%60, align 1, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__202 = (unsigned char )*llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = sext i32 %%storemerge37 to i64, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_653_count);
  llvm_cbe_tmp__203 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__203);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%62, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_654_count);
  llvm_cbe_tmp__204 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__203))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__203));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__203) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%61, i8* %%63, align 1, !dbg !15 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_655_count);
  *llvm_cbe_tmp__204 = llvm_cbe_tmp__202;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__202);
  goto llvm_cbe_tmp__230;

llvm_cbe_tmp__228:
  if ((((signed int )llvm_cbe_tmp__196) < ((signed int )llvm_cbe_tmp__197))) {
    goto llvm_cbe_tmp__231;
  } else {
    goto llvm_cbe_tmp__232;
  }

llvm_cbe_tmp__233:
  goto llvm_cbe_tmp__230;

llvm_cbe_tmp__232:
  if ((((signed int )llvm_cbe_tmp__196) > ((signed int )llvm_cbe_tmp__197))) {
    goto llvm_cbe_tmp__234;
  } else {
    goto llvm_cbe_tmp__233;
  }

llvm_cbe_tmp__234:
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = sext i32 %%storemerge37 to i64, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_659_count);
  llvm_cbe_tmp__205 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 %%12, i64 %%67, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_660_count);
  llvm_cbe_tmp__206 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__173))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )llvm_cbe_tmp__205))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__173));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__205));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__205) < 512 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 48, i8* %%68, align 1, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_661_count);
  *llvm_cbe_tmp__206 = ((unsigned char )48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )48));
  goto llvm_cbe_tmp__233;

  } while (1); /* end of syntactic loop '.preheader..preheader.split_crit_edge' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 10) nounwind, !dbg !19 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__210 = ( char *)(&(*llvm_cbe_messageBlocks)[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 0, i8* %%75) nounwind, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_698_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), 0u, ( char *)llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__211);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds [512 x i8]* %%messageBlocks, i64 1, i64 0, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__212 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 512
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 1, i8* %%77) nounwind, !dbg !16 for 0x%I64xth hint within @padv3  --> \n", ++aesl_llvm_cbe_705_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), 1u, ( char *)llvm_cbe_tmp__212);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__213);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padv3}\n");
  return;
}


signed int padv4( char *llvm_cbe_message,  char (*llvm_cbe_messageBlocks)[513]) {
  static  unsigned long long aesl_llvm_cbe_messageLengthInBinary2_count = 0;
   char llvm_cbe_messageLengthInBinary2[65];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  unsigned int llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge_2e_in;
  unsigned int llvm_cbe_storemerge_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned int llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  unsigned int llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned int llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned int llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge114_count = 0;
  unsigned int llvm_cbe_storemerge114;
  unsigned int llvm_cbe_storemerge114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  unsigned long long llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
   char *llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  unsigned char llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  unsigned int llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  unsigned long long llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  unsigned int llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
   char *llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  unsigned int llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  unsigned int llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge25_2e_lcssa;
  unsigned int llvm_cbe_storemerge25_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned int llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  unsigned long long llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  unsigned int llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  unsigned long long llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
   char *llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_count = 0;
  unsigned int llvm_cbe_storemerge28;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  unsigned int llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  unsigned int llvm_cbe_tmp__256;
  unsigned int llvm_cbe_tmp__256__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned int llvm_cbe_storemerge29;
  unsigned int llvm_cbe_storemerge29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned int llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  unsigned long long llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
   char *llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  unsigned int llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  unsigned int llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
   char *llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
   char *llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_count = 0;
  unsigned int llvm_cbe_storemerge37;
  unsigned int llvm_cbe_storemerge37__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
   char *llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  unsigned char llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  unsigned int llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  unsigned long long llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
   char *llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  unsigned int llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
   char *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge46_count = 0;
  unsigned int llvm_cbe_storemerge46;
  unsigned int llvm_cbe_storemerge46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  unsigned long long llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
   char *llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  unsigned int llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  unsigned int llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padv4\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_724_count);
  llvm_cbe_tmp__235 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__235);
}
  llvm_cbe_storemerge_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__235;   /* for PHI node */
  goto llvm_cbe_tmp__278;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__278:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.in = phi i32 [ %%1, %%0 ], [ %%storemerge, %%2  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge_2e_in_count);
  llvm_cbe_storemerge_2e_in = (unsigned int )llvm_cbe_storemerge_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge.in = 0x%X",llvm_cbe_storemerge_2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__235);
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = add nsw i32 %%storemerge.in, 1, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )((unsigned int )(llvm_cbe_storemerge_2e_in&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = srem i32 %%storemerge, 512, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__236 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__236));
  if (((llvm_cbe_tmp__236&4294967295U) == (448u&4294967295U))) {
    goto llvm_cbe_tmp__279;
  } else {
    llvm_cbe_storemerge_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge;   /* for PHI node */
    goto llvm_cbe_tmp__278;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__279:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sdiv i32 %%storemerge, 512, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__237 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge) / ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__237));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%6, 1, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__238 = (unsigned int )((unsigned int )(llvm_cbe_tmp__237&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__238&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__239 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__239);
}
  if ((((signed int )llvm_cbe_tmp__239) > ((signed int )0u))) {
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  } else {
    llvm_cbe_storemerge25_2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge17;
  }

  do {     /* Syntactic loop '.lr.ph16' to make GCC happy */
llvm_cbe__2e_lr_2e_ph16:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge114 = phi i32 [ %%18, %%.lr.ph16 ], [ 0, %%5  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge114_count);
  llvm_cbe_storemerge114 = (unsigned int )llvm_cbe_storemerge114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge114 = 0x%X",llvm_cbe_storemerge114);
printf("\n = 0x%X",llvm_cbe_tmp__248);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge114 to i64, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_763_count);
  llvm_cbe_tmp__240 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge114);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%message, i64 %%10, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_764_count);
  llvm_cbe_tmp__241 = ( char *)(&llvm_cbe_message[(((signed long long )llvm_cbe_tmp__240))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__240));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%11, align 1, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_765_count);
  llvm_cbe_tmp__242 = (unsigned char )*llvm_cbe_tmp__241;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = srem i32 %%storemerge114, 512, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_766_count);
  llvm_cbe_tmp__243 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge114) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__243));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_767_count);
  llvm_cbe_tmp__244 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__243);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__244);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sdiv i32 %%storemerge114, 512, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__245 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge114) / ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__245));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__246 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%16, i64 %%14, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__247 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__246))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )llvm_cbe_tmp__244))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__246));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__244));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__244) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%17, align 1, !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_771_count);
  *llvm_cbe_tmp__247 = llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge114, 1, !dbg !18 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_772_count);
  llvm_cbe_tmp__248 = (unsigned int )((unsigned int )(llvm_cbe_storemerge114&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__248&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 @getStringLength(i8* %%message), !dbg !14 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_788_count);
  llvm_cbe_tmp__249 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__249);
}
  if ((((signed int )llvm_cbe_tmp__248) < ((signed int )llvm_cbe_tmp__249))) {
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__248;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  } else {
    llvm_cbe_storemerge25_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__248;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge17;
  }

  } while (1); /* end of syntactic loop '.lr.ph16' */
llvm_cbe__2e__crit_edge17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25.lcssa = phi i32 [ 0, %%5 ], [ %%18, %%.lr.ph16  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge25_2e_lcssa_count);
  llvm_cbe_storemerge25_2e_lcssa = (unsigned int )llvm_cbe_storemerge25_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25.lcssa = 0x%X",llvm_cbe_storemerge25_2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__248);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = srem i32 %%storemerge25.lcssa, 512, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__250 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge25_2e_lcssa) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__250));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%21 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_792_count);
  llvm_cbe_tmp__251 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__251);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sdiv i32 %%storemerge25.lcssa, 512, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_793_count);
  llvm_cbe_tmp__252 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge25_2e_lcssa) / ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__252));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_794_count);
  llvm_cbe_tmp__253 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%24, i64 %%22, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_795_count);
  llvm_cbe_tmp__254 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__253))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )llvm_cbe_tmp__251))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__253));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__251));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__251) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 49, i8* %%25, align 1, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_796_count);
  *llvm_cbe_tmp__254 = ((unsigned char )49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )49));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28 = add nsw i32 %%storemerge25.lcssa, 1, !dbg !17 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge28_count);
  llvm_cbe_storemerge28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_lcssa&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge28 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge28&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = srem i32 %%storemerge28, 512, !dbg !17 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__255 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge28) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__255));
  if (((llvm_cbe_tmp__255&4294967295U) == (447u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge12;
  } else {
    llvm_cbe_tmp__256__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__255;   /* for PHI node */
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph11;
  }

  do {     /* Syntactic loop '.lr.ph11' to make GCC happy */
llvm_cbe__2e_lr_2e_ph11:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = phi i32 [ %%33, %%.lr.ph11 ], [ %%26, %%._crit_edge17  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__256 = (unsigned int )llvm_cbe_tmp__256__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__256);
printf("\n = 0x%X",llvm_cbe_tmp__261);
printf("\n = 0x%X",llvm_cbe_tmp__255);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i32 [ %%storemerge2, %%.lr.ph11 ], [ %%storemerge28, %%._crit_edge17  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned int )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%X",llvm_cbe_storemerge29);
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\nstoremerge28 = 0x%X",llvm_cbe_storemerge28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__257 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sdiv i32 %%storemerge29, 512, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__258 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge29) / ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__258));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sext i32 %%30 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_813_count);
  llvm_cbe_tmp__259 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__258);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%31, i64 %%29, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_814_count);
  llvm_cbe_tmp__260 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__259))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )llvm_cbe_tmp__257))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__259));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__257));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__257) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 48, i8* %%32, align 1, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_815_count);
  *llvm_cbe_tmp__260 = ((unsigned char )48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )48));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = add nsw i32 %%storemerge29, 1, !dbg !17 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )((unsigned int )(llvm_cbe_storemerge29&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge2 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = srem i32 %%storemerge2, 512, !dbg !17 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__261 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge2) % ((signed int )512u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__261));
  if (((llvm_cbe_tmp__261&4294967295U) == (447u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge12;
  } else {
    llvm_cbe_tmp__256__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__261;   /* for PHI node */
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge2;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph11;
  }

  } while (1); /* end of syntactic loop '.lr.ph11' */
llvm_cbe__2e__crit_edge12:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i32 @getStringLength(i8* %%message), !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_830_count);
  llvm_cbe_tmp__262 = (unsigned int )getStringLength(( char *)llvm_cbe_message);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__262);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary2, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__263 = ( char *)(&llvm_cbe_messageLengthInBinary2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i8* @numToBinary(i32 %%35, i8* %%36, i32 64), !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_832_count);
  ( char *)numToBinary(llvm_cbe_tmp__262, ( char *)llvm_cbe_tmp__263, 64u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__262);
printf("\nArgument  = 0x%X",64u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__264);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i32 %%6 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_838_count);
  llvm_cbe_tmp__265 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__265);
  llvm_cbe_storemerge37__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__280;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__280:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37 = phi i32 [ 0, %%._crit_edge12 ], [ %%46, %%39  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge37_count);
  llvm_cbe_storemerge37 = (unsigned int )llvm_cbe_storemerge37__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37 = 0x%X",llvm_cbe_storemerge37);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__272);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%storemerge37 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_840_count);
  llvm_cbe_tmp__266 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [65 x i8]* %%messageLengthInBinary2, i64 0, i64 %%40, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_841_count);
  llvm_cbe_tmp__267 = ( char *)(&llvm_cbe_messageLengthInBinary2[(((signed long long )llvm_cbe_tmp__266))
#ifdef AESL_BC_SIM
 % 65
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__266));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__266) < 65)) fprintf(stderr, "%s:%d: warning: Read access out of array 'messageLengthInBinary2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_842_count);
  llvm_cbe_tmp__268 = (unsigned char )*llvm_cbe_tmp__267;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add nsw i32 %%storemerge37, 448, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_843_count);
  llvm_cbe_tmp__269 = (unsigned int )((unsigned int )(llvm_cbe_storemerge37&4294967295ull)) + ((unsigned int )(448u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__269&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_844_count);
  llvm_cbe_tmp__270 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__270);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%38, i64 %%44, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_845_count);
  llvm_cbe_tmp__271 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__265))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )llvm_cbe_tmp__270))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__265));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__270));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__270) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%45, align 1, !dbg !15 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_846_count);
  *llvm_cbe_tmp__271 = llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%storemerge37, 1, !dbg !18 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_847_count);
  llvm_cbe_tmp__272 = (unsigned int )((unsigned int )(llvm_cbe_storemerge37&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__272&4294967295ull)));
  if (((llvm_cbe_tmp__272&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__281;
  } else {
    llvm_cbe_storemerge37__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__272;   /* for PHI node */
    goto llvm_cbe_tmp__280;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__281:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%38, i64 512, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_854_count);
  llvm_cbe_tmp__273 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__265))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )512ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__265));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )512ull) < 513 && "Write access out of array 'messageBlocks' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%48, align 1, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_855_count);
  *llvm_cbe_tmp__273 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 10) nounwind, !dbg !19 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
  if ((((signed int )llvm_cbe_tmp__238) > ((signed int )0u))) {
    llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge46 = phi i32 [ %%53, %%.lr.ph ], [ 0, %%47  for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_storemerge46_count);
  llvm_cbe_storemerge46 = (unsigned int )llvm_cbe_storemerge46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge46 = 0x%X",llvm_cbe_storemerge46);
printf("\n = 0x%X",llvm_cbe_tmp__277);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%storemerge46 to i64, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_863_count);
  llvm_cbe_tmp__274 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [513 x i8]* %%messageBlocks, i64 %%50, i64 0, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_864_count);
  llvm_cbe_tmp__275 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__274))
#ifdef AESL_BC_SIM
 % 513
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__274));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 %%storemerge46, i8* %%51) nounwind, !dbg !16 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_865_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), llvm_cbe_storemerge46, ( char *)llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge46 = 0x%X",llvm_cbe_storemerge46);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__276);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add nsw i32 %%storemerge46, 1, !dbg !19 for 0x%I64xth hint within @padv4  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__277 = (unsigned int )((unsigned int )(llvm_cbe_storemerge46&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__277&4294967295ull)));
  if (((llvm_cbe_tmp__277&4294967295U) == (llvm_cbe_tmp__238&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__277;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padv4}\n");
  return llvm_cbe_tmp__238;
}


signed int binaryToInt( char *llvm_cbe_binaryString) {
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  unsigned char llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  unsigned char llvm_cbe_tmp__283;
  unsigned char llvm_cbe_tmp__283__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  unsigned int llvm_cbe_tmp__284;
  unsigned int llvm_cbe_tmp__284__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  unsigned int llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  unsigned int llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  unsigned int llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
   char *llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  unsigned char llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @binaryToInt\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* %%binaryString, align 1, !dbg !14 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_884_count);
  llvm_cbe_tmp__282 = (unsigned char )*llvm_cbe_binaryString;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__282);
  if (((llvm_cbe_tmp__282&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__282;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__284__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i8 [ %%10, %%.lr.ph ], [ %%1, %%0  for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__283 = (unsigned char )llvm_cbe_tmp__283__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__283);
printf("\n = 0x%X",llvm_cbe_tmp__289);
printf("\n = 0x%X",llvm_cbe_tmp__282);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec2, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i32 [ %%8, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__284 = (unsigned int )llvm_cbe_tmp__284__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__284);
printf("\n = 0x%X",llvm_cbe_tmp__287);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl i32 %%4, 1, !dbg !15 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__285 = (unsigned int )llvm_cbe_tmp__284 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i32 %%5, 1, !dbg !15 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__286 = (unsigned int )llvm_cbe_tmp__285 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = select i1 %%6, i32 %%7, i32 %%5, !dbg !15 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__287 = (unsigned int )((((llvm_cbe_tmp__283&255U) == (((unsigned char )49)&255U))) ? ((unsigned int )llvm_cbe_tmp__286) : ((unsigned int )llvm_cbe_tmp__285));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, 1, !dbg !15 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%binaryString, i64 %%.rec2, !dbg !15 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__288 = ( char *)(&llvm_cbe_binaryString[(((signed long long )llvm_cbe__2e_rec2))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec2 = 0x%I64X",((signed long long )llvm_cbe__2e_rec2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !14 for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe_907_count);
  llvm_cbe_tmp__289 = (unsigned char )*llvm_cbe_tmp__288;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__289);
  if (((llvm_cbe_tmp__289&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__287;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__289;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    llvm_cbe_tmp__284__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__287;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ 0, %%0 ], [ %%8, %%.lr.ph  for 0x%I64xth hint within @binaryToInt  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__287);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @binaryToInt}\n");
  return llvm_cbe__2e_lcssa;
}


signed int rotateRightint(signed int llvm_cbe_x, signed int llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  unsigned int llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  unsigned int llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  unsigned int llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  unsigned int llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  unsigned int llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  unsigned int llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @rotateRightint\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = and i32 %%n, 31, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_915_count);
  llvm_cbe_tmp__290 = (unsigned int )llvm_cbe_n & 31u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = lshr i32 %%x, %%1, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__291 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_x&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__290&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__291&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sub i32 0, %%n, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_919_count);
  llvm_cbe_tmp__292 = (unsigned int )-(llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__292&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = and i32 %%3, 31, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_920_count);
  llvm_cbe_tmp__293 = (unsigned int )llvm_cbe_tmp__292 & 31u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl i32 %%x, %%4, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_921_count);
  llvm_cbe_tmp__294 = (unsigned int )llvm_cbe_x << llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__294);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = or i32 %%2, %%5, !dbg !14 for 0x%I64xth hint within @rotateRightint  --> \n", ++aesl_llvm_cbe_922_count);
  llvm_cbe_tmp__295 = (unsigned int )llvm_cbe_tmp__291 | llvm_cbe_tmp__294;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__295);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @rotateRightint}\n");
  return llvm_cbe_tmp__295;
}


void createMessageSchedule( char *llvm_cbe_messageBlock, signed int *llvm_cbe_messageSchedule) {
  static  unsigned long long aesl_llvm_cbe_splitBlock_count = 0;
   char llvm_cbe_splitBlock[33];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
   char *llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
   char *llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge9_count = 0;
  unsigned int llvm_cbe_storemerge9;
  unsigned int llvm_cbe_storemerge9__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  unsigned int llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge38_count = 0;
  unsigned int llvm_cbe_storemerge38;
  unsigned int llvm_cbe_storemerge38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  unsigned int llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  unsigned long long llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
   char *llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned char llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
   char *llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  unsigned int llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  unsigned int llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  unsigned long long llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  signed int *llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  unsigned int llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond12_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned int llvm_cbe_storemerge16;
  unsigned int llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned long long llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  signed int *llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  unsigned int llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge24_count = 0;
  unsigned int llvm_cbe_storemerge24;
  unsigned int llvm_cbe_storemerge24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  unsigned int llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  unsigned long long llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  signed int *llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  unsigned int llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  unsigned int llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  unsigned int llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  unsigned int llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  unsigned int llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  unsigned int llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  unsigned int llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  unsigned long long llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  signed int *llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  unsigned int llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  unsigned int llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  unsigned int llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  unsigned int llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned int llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  unsigned int llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  unsigned int llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  unsigned long long llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  signed int *llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  unsigned int llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  unsigned int llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  unsigned long long llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  signed int *llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  unsigned int llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  unsigned int llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  unsigned int llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  unsigned int llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  unsigned long long llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  signed int *llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  unsigned int llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @createMessageSchedule\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [33 x i8]* %%splitBlock, i64 0, i64 32, !dbg !18 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_964_count);
  llvm_cbe_tmp__296 = ( char *)(&llvm_cbe_splitBlock[(((signed long long )32ull))
#ifdef AESL_BC_SIM
 % 33
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [33 x i8]* %%splitBlock, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_965_count);
  llvm_cbe_tmp__297 = ( char *)(&llvm_cbe_splitBlock[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 33
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader7;

  do {     /* Syntactic loop '.preheader7' to make GCC happy */
llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge9 = phi i32 [ 0, %%0 ], [ %%16, %%12  for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_storemerge9_count);
  llvm_cbe_storemerge9 = (unsigned int )llvm_cbe_storemerge9__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge9 = 0x%X",llvm_cbe_storemerge9);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__309);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i32 %%storemerge9, 5, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__298 = (unsigned int )llvm_cbe_storemerge9 << 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__298);
  llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__345;

llvm_cbe_tmp__346:

#ifdef AESL_BC_SIM
  assert(((signed long long )32ull) < 33 && "Write access out of array 'splitBlock' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%1, align 16, !dbg !18 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_987_count);
  *llvm_cbe_tmp__296 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i32 @binaryToInt(i8* %%2), !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__306 = (unsigned int )binaryToInt(( char *)llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__306);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%storemerge9 to i64, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_989_count);
  llvm_cbe_tmp__307 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i32* %%messageSchedule, i64 %%14, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__308 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__307))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__307));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* %%15, align 4, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_991_count);
  *llvm_cbe_tmp__308 = llvm_cbe_tmp__306;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__306);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge9, 1, !dbg !17 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__309 = (unsigned int )((unsigned int )(llvm_cbe_storemerge9&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__309&4294967295ull)));
  if (((llvm_cbe_tmp__309&4294967295U) == (16u&4294967295U))) {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )16u;   /* for PHI node */
    goto llvm_cbe__2e_preheader5;
  } else {
    llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__309;   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__345:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge38 = phi i32 [ 0, %%.preheader7 ], [ %%11, %%4  for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_storemerge38_count);
  llvm_cbe_storemerge38 = (unsigned int )llvm_cbe_storemerge38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge38 = 0x%X",llvm_cbe_storemerge38);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__305);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%storemerge38, %%3, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_973_count);
  llvm_cbe_tmp__299 = (unsigned int )((unsigned int )(llvm_cbe_storemerge38&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__298&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__299&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%5 to i64, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__300 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__300);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%messageBlock, i64 %%6, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__301 = ( char *)(&llvm_cbe_messageBlock[(((signed long long )llvm_cbe_tmp__300))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__300));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__302 = (unsigned char )*llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sext i32 %%storemerge38 to i64, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__303 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge38);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [33 x i8]* %%splitBlock, i64 0, i64 %%9, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__304 = ( char *)(&llvm_cbe_splitBlock[(((signed long long )llvm_cbe_tmp__303))
#ifdef AESL_BC_SIM
 % 33
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__303));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__303) < 33 && "Write access out of array 'splitBlock' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%10, align 1, !dbg !14 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_979_count);
  *llvm_cbe_tmp__304 = llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge38, 1, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_980_count);
  llvm_cbe_tmp__305 = (unsigned int )((unsigned int )(llvm_cbe_storemerge38&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__305&4294967295ull)));
  if (((llvm_cbe_tmp__305&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe_tmp__346;
  } else {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__305;   /* for PHI node */
    goto llvm_cbe_tmp__345;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader7' */
  do {     /* Syntactic loop '.preheader5' to make GCC happy */
llvm_cbe__2e_preheader5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i32 [ %%19, %%.preheader5 ], [ 16, %%12  for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned int )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",llvm_cbe_tmp__312);
printf("\n = 0x%X",16u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sext i32 %%storemerge16 to i64, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__310 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i32* %%messageSchedule, i64 %%17, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1014_count);
  llvm_cbe_tmp__311 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__310))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__310));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%18, align 4, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1015_count);
  *llvm_cbe_tmp__311 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%storemerge16, 1, !dbg !17 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1016_count);
  llvm_cbe_tmp__312 = (unsigned int )((unsigned int )(llvm_cbe_storemerge16&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__312&4294967295ull)));
  if (((llvm_cbe_tmp__312&4294967295U) == (64u&4294967295U))) {
    llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )16u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__312;   /* for PHI node */
    goto llvm_cbe__2e_preheader5;
  }

  } while (1); /* end of syntactic loop '.preheader5' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge24 = phi i32 [ %%51, %%.preheader ], [ 16, %%.preheader5  for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_storemerge24_count);
  llvm_cbe_storemerge24 = (unsigned int )llvm_cbe_storemerge24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%X",llvm_cbe_storemerge24);
printf("\n = 0x%X",llvm_cbe_tmp__344);
printf("\n = 0x%X",16u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%storemerge24, -15, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1037_count);
  llvm_cbe_tmp__313 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(4294967281u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__313&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__314 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__314);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i32* %%messageSchedule, i64 %%21, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__315 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__314))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__314));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1040_count);
  llvm_cbe_tmp__316 = (unsigned int )*llvm_cbe_tmp__315;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i32 @rotateRightint(i32 %%23, i32 7), !dbg !15 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__317 = (unsigned int )rotateRightint(llvm_cbe_tmp__316, 7u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__316);
printf("\nArgument  = 0x%X",7u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__317);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call i32 @rotateRightint(i32 %%23, i32 18), !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1042_count);
  llvm_cbe_tmp__318 = (unsigned int )rotateRightint(llvm_cbe_tmp__316, 18u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__316);
printf("\nArgument  = 0x%X",18u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__318);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = lshr i32 %%23, 3, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__319 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__316&4294967295ull)) >> ((unsigned int )(3u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__319&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = xor i32 %%24, %%26, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__320 = (unsigned int )llvm_cbe_tmp__317 ^ llvm_cbe_tmp__319;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = xor i32 %%27, %%25, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1045_count);
  llvm_cbe_tmp__321 = (unsigned int )llvm_cbe_tmp__320 ^ llvm_cbe_tmp__318;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__321);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge24, -2, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1048_count);
  llvm_cbe_tmp__322 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(4294967294u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__322&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1049_count);
  llvm_cbe_tmp__323 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__323);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i32* %%messageSchedule, i64 %%30, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1050_count);
  llvm_cbe_tmp__324 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__323))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__323));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i32* %%31, align 4, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1051_count);
  llvm_cbe_tmp__325 = (unsigned int )*llvm_cbe_tmp__324;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = call i32 @rotateRightint(i32 %%32, i32 17), !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__326 = (unsigned int )rotateRightint(llvm_cbe_tmp__325, 17u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__325);
printf("\nArgument  = 0x%X",17u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__326);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i32 @rotateRightint(i32 %%32, i32 19), !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1053_count);
  llvm_cbe_tmp__327 = (unsigned int )rotateRightint(llvm_cbe_tmp__325, 19u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__325);
printf("\nArgument  = 0x%X",19u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__327);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = lshr i32 %%32, 10, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1054_count);
  llvm_cbe_tmp__328 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__325&4294967295ull)) >> ((unsigned int )(10u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__328&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = xor i32 %%33, %%35, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__329 = (unsigned int )llvm_cbe_tmp__326 ^ llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = xor i32 %%36, %%34, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__330 = (unsigned int )llvm_cbe_tmp__329 ^ llvm_cbe_tmp__327;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add nsw i32 %%storemerge24, -16, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1059_count);
  llvm_cbe_tmp__331 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(4294967280u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__331&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = sext i32 %%38 to i64, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1060_count);
  llvm_cbe_tmp__332 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__331);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__332);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i32* %%messageSchedule, i64 %%39, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1061_count);
  llvm_cbe_tmp__333 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__332))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__332));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i32* %%40, align 4, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__334 = (unsigned int )*llvm_cbe_tmp__333;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__334);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge24, -7, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1063_count);
  llvm_cbe_tmp__335 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(4294967289u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__335&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%42 to i64, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__336 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i32* %%messageSchedule, i64 %%43, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__337 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__336))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__336));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i32* %%44, align 4, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1066_count);
  llvm_cbe_tmp__338 = (unsigned int )*llvm_cbe_tmp__337;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i32 %%37, %%28, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1067_count);
  llvm_cbe_tmp__339 = (unsigned int )((unsigned int )(llvm_cbe_tmp__330&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__321&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__339&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i32 %%46, %%41, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1068_count);
  llvm_cbe_tmp__340 = (unsigned int )((unsigned int )(llvm_cbe_tmp__339&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__334&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__340&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i32 %%47, %%45, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1069_count);
  llvm_cbe_tmp__341 = (unsigned int )((unsigned int )(llvm_cbe_tmp__340&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__338&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__341&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = sext i32 %%storemerge24 to i64, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1070_count);
  llvm_cbe_tmp__342 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge24);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__342);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds i32* %%messageSchedule, i64 %%49, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1071_count);
  llvm_cbe_tmp__343 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__342))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__342));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%48, i32* %%50, align 4, !dbg !16 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1072_count);
  *llvm_cbe_tmp__343 = llvm_cbe_tmp__341;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__341);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add nsw i32 %%storemerge24, 1, !dbg !18 for 0x%I64xth hint within @createMessageSchedule  --> \n", ++aesl_llvm_cbe_1073_count);
  llvm_cbe_tmp__344 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__344&4294967295ull)));
  if (((llvm_cbe_tmp__344&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__347;
  } else {
    llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__344;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__347:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @createMessageSchedule}\n");
  return;
}


signed int choice(signed int llvm_cbe_x, signed int llvm_cbe_y, signed int llvm_cbe_z) {
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  unsigned int llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  unsigned int llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  unsigned int llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  unsigned int llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @choice\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = and i32 %%y, %%x, !dbg !15 for 0x%I64xth hint within @choice  --> \n", ++aesl_llvm_cbe_1100_count);
  llvm_cbe_tmp__348 = (unsigned int )llvm_cbe_y & llvm_cbe_x;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__348);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = xor i32 %%x, -1, !dbg !15 for 0x%I64xth hint within @choice  --> \n", ++aesl_llvm_cbe_1102_count);
  llvm_cbe_tmp__349 = (unsigned int )llvm_cbe_x ^ 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__349);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = and i32 %%z, %%2, !dbg !15 for 0x%I64xth hint within @choice  --> \n", ++aesl_llvm_cbe_1104_count);
  llvm_cbe_tmp__350 = (unsigned int )llvm_cbe_z & llvm_cbe_tmp__349;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__350);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%3, %%1, !dbg !15 for 0x%I64xth hint within @choice  --> \n", ++aesl_llvm_cbe_1105_count);
  llvm_cbe_tmp__351 = (unsigned int )llvm_cbe_tmp__350 ^ llvm_cbe_tmp__348;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__351);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @choice}\n");
  return llvm_cbe_tmp__351;
}


signed int majority(signed int llvm_cbe_x, signed int llvm_cbe_y, signed int llvm_cbe_z) {
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  unsigned int llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  unsigned int llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  unsigned int llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  unsigned int llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @majority\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = xor i32 %%z, %%y, !dbg !15 for 0x%I64xth hint within @majority  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__352 = (unsigned int )llvm_cbe_z ^ llvm_cbe_y;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__352);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = and i32 %%1, %%x, !dbg !15 for 0x%I64xth hint within @majority  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__353 = (unsigned int )llvm_cbe_tmp__352 & llvm_cbe_x;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__353);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = and i32 %%z, %%y, !dbg !15 for 0x%I64xth hint within @majority  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__354 = (unsigned int )llvm_cbe_z & llvm_cbe_y;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%2, %%3, !dbg !15 for 0x%I64xth hint within @majority  --> \n", ++aesl_llvm_cbe_1119_count);
  llvm_cbe_tmp__355 = (unsigned int )llvm_cbe_tmp__353 ^ llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__355);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @majority}\n");
  return llvm_cbe_tmp__355;
}


void compression(signed int *llvm_cbe_messageSchedule) {
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  unsigned int llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  unsigned int llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  unsigned int llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  unsigned int llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  unsigned int llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  unsigned int llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  unsigned int llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  unsigned int llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  unsigned int llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  unsigned int llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  unsigned int llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  unsigned int llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  unsigned int llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  unsigned int llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  unsigned int llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned int llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  unsigned int llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  unsigned long long llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  signed int *llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  unsigned int llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  signed int *llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  unsigned int llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  unsigned int llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  unsigned int llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  unsigned int llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  unsigned int llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  unsigned int llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  unsigned int llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  unsigned int llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  unsigned int llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  unsigned int llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  unsigned int llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  unsigned int llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  unsigned int llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  unsigned int llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  unsigned int llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  unsigned int llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  unsigned int llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  unsigned int llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @compression\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 0), align 16, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1123_count);
  llvm_cbe_tmp__356 = (unsigned int )*((&hash[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%1, i32* @a, align 4, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1124_count);
  *(&a) = llvm_cbe_tmp__356;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 1), align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1125_count);
  llvm_cbe_tmp__357 = (unsigned int )*((&hash[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__357);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* @b, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1126_count);
  *(&b) = llvm_cbe_tmp__357;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__357);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1127_count);
  llvm_cbe_tmp__358 = (unsigned int )*((&hash[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__358);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%3, i32* @c, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1128_count);
  *(&c) = llvm_cbe_tmp__358;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__358);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 3), align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1129_count);
  llvm_cbe_tmp__359 = (unsigned int )*((&hash[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* @d, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1130_count);
  *(&d) = llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 4), align 16, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1131_count);
  llvm_cbe_tmp__360 = (unsigned int )*((&hash[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* @e, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1132_count);
  *(&e) = llvm_cbe_tmp__360;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 5), align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1133_count);
  llvm_cbe_tmp__361 = (unsigned int )*((&hash[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__361);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* @f, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1134_count);
  *(&f) = llvm_cbe_tmp__361;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__361);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 6), align 8, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1135_count);
  llvm_cbe_tmp__362 = (unsigned int )*((&hash[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* @g, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1136_count);
  *(&g) = llvm_cbe_tmp__362;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 7), align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1137_count);
  llvm_cbe_tmp__363 = (unsigned int )*((&hash[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%8, i32* @h, align 4, !dbg !15 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1138_count);
  *(&h) = llvm_cbe_tmp__363;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__363);
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__397;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__397:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%42, %%9  for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__396);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* @e, align 4, !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__364 = (unsigned int )*(&e);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 @rotateRightint(i32 %%10, i32 6), !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1162_count);
  llvm_cbe_tmp__365 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__364, 6u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__364);
printf("\nArgument  = 0x%X",6u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__365);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @rotateRightint(i32 %%10, i32 11), !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1163_count);
  llvm_cbe_tmp__366 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__364, 11u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__364);
printf("\nArgument  = 0x%X",11u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__366);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i32 @rotateRightint(i32 %%10, i32 25), !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__367 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__364, 25u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__364);
printf("\nArgument  = 0x%X",25u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__367);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = xor i32 %%12, %%11, !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1165_count);
  llvm_cbe_tmp__368 = (unsigned int )llvm_cbe_tmp__366 ^ llvm_cbe_tmp__365;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__368);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = xor i32 %%14, %%13, !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__369 = (unsigned int )llvm_cbe_tmp__368 ^ llvm_cbe_tmp__367;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__369);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* @f, align 4, !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__370 = (unsigned int )*(&f);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* @g, align 4, !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1170_count);
  llvm_cbe_tmp__371 = (unsigned int )*(&g);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call i32 @choice(i32 %%10, i32 %%16, i32 %%17), !dbg !17 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__372 = (unsigned int ) /*tail*/ choice(llvm_cbe_tmp__364, llvm_cbe_tmp__370, llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__364);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__370);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__371);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__372);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* @h, align 4, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1173_count);
  llvm_cbe_tmp__373 = (unsigned int )*(&h);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__373);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1175_count);
  llvm_cbe_tmp__374 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__374);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [64 x i32]* @constants, i64 0, i64 %%20, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__375 = (signed int *)(&constants[(((signed long long )llvm_cbe_tmp__374))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__374));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__374) < 64)) fprintf(stderr, "%s:%d: warning: Read access out of array 'constants' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1177_count);
  llvm_cbe_tmp__376 = (unsigned int )*llvm_cbe_tmp__375;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__376);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i32* %%messageSchedule, i64 %%20, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1178_count);
  llvm_cbe_tmp__377 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )llvm_cbe_tmp__374))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__374));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%23, align 4, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1179_count);
  llvm_cbe_tmp__378 = (unsigned int )*llvm_cbe_tmp__377;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%18, %%15, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1180_count);
  llvm_cbe_tmp__379 = (unsigned int )((unsigned int )(llvm_cbe_tmp__372&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__369&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__379&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%25, %%19, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1181_count);
  llvm_cbe_tmp__380 = (unsigned int )((unsigned int )(llvm_cbe_tmp__379&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__373&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__380&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%26, %%22, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1182_count);
  llvm_cbe_tmp__381 = (unsigned int )((unsigned int )(llvm_cbe_tmp__380&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__376&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__381&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, %%24, !dbg !14 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1183_count);
  llvm_cbe_tmp__382 = (unsigned int )((unsigned int )(llvm_cbe_tmp__381&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__378&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__382&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* @a, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1187_count);
  llvm_cbe_tmp__383 = (unsigned int )*(&a);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = tail call i32 @rotateRightint(i32 %%29, i32 2), !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1188_count);
  llvm_cbe_tmp__384 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__383, 2u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__383);
printf("\nArgument  = 0x%X",2u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__384);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 @rotateRightint(i32 %%29, i32 13), !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1189_count);
  llvm_cbe_tmp__385 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__383, 13u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__383);
printf("\nArgument  = 0x%X",13u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__385);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = tail call i32 @rotateRightint(i32 %%29, i32 22), !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1190_count);
  llvm_cbe_tmp__386 = (unsigned int ) /*tail*/ rotateRightint(llvm_cbe_tmp__383, 22u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__383);
printf("\nArgument  = 0x%X",22u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__386);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = xor i32 %%31, %%30, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1191_count);
  llvm_cbe_tmp__387 = (unsigned int )llvm_cbe_tmp__385 ^ llvm_cbe_tmp__384;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__387);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = xor i32 %%33, %%32, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1192_count);
  llvm_cbe_tmp__388 = (unsigned int )llvm_cbe_tmp__387 ^ llvm_cbe_tmp__386;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__388);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* @b, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1195_count);
  llvm_cbe_tmp__389 = (unsigned int )*(&b);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* @c, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__390 = (unsigned int )*(&c);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call i32 @majority(i32 %%29, i32 %%35, i32 %%36), !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1197_count);
  llvm_cbe_tmp__391 = (unsigned int ) /*tail*/ majority(llvm_cbe_tmp__383, llvm_cbe_tmp__389, llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__383);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__389);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__390);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__391);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%17, i32* @h, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1200_count);
  *(&h) = llvm_cbe_tmp__371;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* @g, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1201_count);
  *(&g) = llvm_cbe_tmp__370;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%10, i32* @f, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1202_count);
  *(&f) = llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* @d, align 4, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1203_count);
  llvm_cbe_tmp__392 = (unsigned int )*(&d);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__392);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i32 %%38, %%28, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1204_count);
  llvm_cbe_tmp__393 = (unsigned int )((unsigned int )(llvm_cbe_tmp__392&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__382&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__393&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%39, i32* @e, align 4, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1205_count);
  *(&e) = llvm_cbe_tmp__393;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__393);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%36, i32* @d, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1206_count);
  *(&d) = llvm_cbe_tmp__390;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%35, i32* @c, align 4, !dbg !18 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1207_count);
  *(&c) = llvm_cbe_tmp__389;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%29, i32* @b, align 4, !dbg !19 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1208_count);
  *(&b) = llvm_cbe_tmp__383;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i32 %%34, %%28, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1209_count);
  llvm_cbe_tmp__394 = (unsigned int )((unsigned int )(llvm_cbe_tmp__388&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__382&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__394&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i32 %%40, %%37, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1210_count);
  llvm_cbe_tmp__395 = (unsigned int )((unsigned int )(llvm_cbe_tmp__394&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__391&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__395&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%41, i32* @a, align 4, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1211_count);
  *(&a) = llvm_cbe_tmp__395;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__395);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i32 %%storemerge1, 1, !dbg !16 for 0x%I64xth hint within @compression  --> \n", ++aesl_llvm_cbe_1212_count);
  llvm_cbe_tmp__396 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__396&4294967295ull)));
  if (((llvm_cbe_tmp__396&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__398;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__396;   /* for PHI node */
    goto llvm_cbe_tmp__397;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__398:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @compression}\n");
  return;
}


void prep( char *llvm_cbe_message) {
  static  unsigned long long aesl_llvm_cbe_messageBlocks_count = 0;
   char llvm_cbe_messageBlocks[128][513];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_messageSchedule_count = 0;
  signed int llvm_cbe_messageSchedule[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
   char (*llvm_cbe_tmp__399)[513];
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  unsigned int llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  signed int *llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  unsigned long long llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
   char *llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  unsigned int llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  unsigned int llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  unsigned int llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  unsigned int llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  unsigned int llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  unsigned int llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  unsigned int llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  unsigned int llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  unsigned int llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  unsigned int llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  unsigned int llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  unsigned int llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  unsigned int llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  unsigned int llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  unsigned int llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  unsigned int llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  unsigned int llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  unsigned int llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  unsigned int llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  unsigned int llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  unsigned int llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  unsigned int llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  unsigned int llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  unsigned int llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  unsigned int llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  unsigned int llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  unsigned int llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  unsigned int llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  unsigned int llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  unsigned int llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  unsigned int llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  unsigned int llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  unsigned int llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  unsigned int llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @prep\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [128 x [513 x i8]]* %%messageBlocks, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1230_count);
  llvm_cbe_tmp__399 = ( char (*)[513])(&llvm_cbe_messageBlocks[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @padv4(i8* %%message, [513 x i8]* %%1), !dbg !14 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1231_count);
  llvm_cbe_tmp__400 = (unsigned int )padv4(( char *)llvm_cbe_message, llvm_cbe_tmp__399);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__400);
}
  if ((((signed int )llvm_cbe_tmp__400) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [64 x i32]* %%messageSchedule, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1240_count);
  llvm_cbe_tmp__401 = (signed int *)(&llvm_cbe_messageSchedule[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__438;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__438:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%.lr.ph ], [ %%32, %%5  for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__428);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge1 to i64, !dbg !16 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1243_count);
  llvm_cbe_tmp__402 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__402);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [128 x [513 x i8]]* %%messageBlocks, i64 0, i64 %%6, i64 0, !dbg !16 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1244_count);
  llvm_cbe_tmp__403 = ( char *)(&llvm_cbe_messageBlocks[(((signed long long )llvm_cbe_tmp__402))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 513
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__402));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @createMessageSchedule(i8* %%7, i32* %%4), !dbg !16 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1245_count);
  createMessageSchedule(( char *)llvm_cbe_tmp__403, (signed int *)llvm_cbe_tmp__401);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @compression(i32* %%4), !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1246_count);
  compression((signed int *)llvm_cbe_tmp__401);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* @a, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1247_count);
  llvm_cbe_tmp__404 = (unsigned int )*(&a);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__404);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__405 = (unsigned int )*((&hash[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%9, %%8, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1249_count);
  llvm_cbe_tmp__406 = (unsigned int )((unsigned int )(llvm_cbe_tmp__405&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__404&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__406&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%10, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1250_count);
  *((&hash[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__406;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__406);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* @b, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1251_count);
  llvm_cbe_tmp__407 = (unsigned int )*(&b);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__407);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 1), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1252_count);
  llvm_cbe_tmp__408 = (unsigned int )*((&hash[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__408);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i32 %%12, %%11, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1253_count);
  llvm_cbe_tmp__409 = (unsigned int )((unsigned int )(llvm_cbe_tmp__408&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__407&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__409&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 1), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1254_count);
  *((&hash[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__409;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* @c, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1255_count);
  llvm_cbe_tmp__410 = (unsigned int )*(&c);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__410);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__411 = (unsigned int )*((&hash[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__411);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%15, %%14, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1257_count);
  llvm_cbe_tmp__412 = (unsigned int )((unsigned int )(llvm_cbe_tmp__411&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__410&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__412&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1258_count);
  *((&hash[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__412;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* @d, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__413 = (unsigned int )*(&d);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 3), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__414 = (unsigned int )*((&hash[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__414);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%18, %%17, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1261_count);
  llvm_cbe_tmp__415 = (unsigned int )((unsigned int )(llvm_cbe_tmp__414&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__413&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__415&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%19, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 3), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1262_count);
  *((&hash[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__415;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i32* @e, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1263_count);
  llvm_cbe_tmp__416 = (unsigned int )*(&e);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__416);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 4), align 16, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1264_count);
  llvm_cbe_tmp__417 = (unsigned int )*((&hash[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__417);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i32 %%21, %%20, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1265_count);
  llvm_cbe_tmp__418 = (unsigned int )((unsigned int )(llvm_cbe_tmp__417&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__416&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__418&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 4), align 16, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1266_count);
  *((&hash[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__418;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__418);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* @f, align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1267_count);
  llvm_cbe_tmp__419 = (unsigned int )*(&f);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__419);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 5), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__420 = (unsigned int )*((&hash[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__420);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%24, %%23, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1269_count);
  llvm_cbe_tmp__421 = (unsigned int )((unsigned int )(llvm_cbe_tmp__420&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__419&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__421&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%25, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 5), align 4, !dbg !17 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1270_count);
  *((&hash[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__421;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* @g, align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1271_count);
  llvm_cbe_tmp__422 = (unsigned int )*(&g);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 6), align 8, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1272_count);
  llvm_cbe_tmp__423 = (unsigned int )*((&hash[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__423);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, %%26, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1273_count);
  llvm_cbe_tmp__424 = (unsigned int )((unsigned int )(llvm_cbe_tmp__423&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__422&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__424&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 6), align 8, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1274_count);
  *((&hash[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__424;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* @h, align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__425 = (unsigned int )*(&h);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__425);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 7), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1276_count);
  llvm_cbe_tmp__426 = (unsigned int )*((&hash[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__426);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%30, %%29, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1277_count);
  llvm_cbe_tmp__427 = (unsigned int )((unsigned int )(llvm_cbe_tmp__426&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__425&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__427&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%31, i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 7), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1278_count);
  *((&hash[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])) = llvm_cbe_tmp__427;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__427);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge1, 1, !dbg !16 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1279_count);
  llvm_cbe_tmp__428 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__428&4294967295ull)));
  if (((llvm_cbe_tmp__428&4294967295U) == (llvm_cbe_tmp__400&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__428;   /* for PHI node */
    goto llvm_cbe_tmp__438;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 0), align 16, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1285_count);
  llvm_cbe_tmp__429 = (unsigned int )*((&hash[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__429);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 1), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1286_count);
  llvm_cbe_tmp__430 = (unsigned int )*((&hash[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 2), align 8, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1287_count);
  llvm_cbe_tmp__431 = (unsigned int )*((&hash[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 3), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1288_count);
  llvm_cbe_tmp__432 = (unsigned int )*((&hash[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__432);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 4), align 16, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1289_count);
  llvm_cbe_tmp__433 = (unsigned int )*((&hash[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 5), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1290_count);
  llvm_cbe_tmp__434 = (unsigned int )*((&hash[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__434);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 6), align 8, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1291_count);
  llvm_cbe_tmp__435 = (unsigned int )*((&hash[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__435);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* getelementptr inbounds ([8 x i32]* @hash, i64 0, i64 7), align 4, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1292_count);
  llvm_cbe_tmp__436 = (unsigned int )*((&hash[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__436);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([19 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%33, i32 %%34, i32 %%35, i32 %%36, i32 %%37, i32 %%38, i32 %%39, i32 %%40) nounwind, !dbg !18 for 0x%I64xth hint within @prep  --> \n", ++aesl_llvm_cbe_1293_count);
  printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 19
#endif
])), llvm_cbe_tmp__429, llvm_cbe_tmp__430, llvm_cbe_tmp__431, llvm_cbe_tmp__432, llvm_cbe_tmp__433, llvm_cbe_tmp__434, llvm_cbe_tmp__435, llvm_cbe_tmp__436);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__429);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__430);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__431);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__432);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__433);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__434);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__435);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__436);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__437);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @prep}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_message5binary_count = 0;
   char llvm_cbe_message5binary[2617];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
   char *llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
   char *llvm_cbe_tmp__440;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [2617 x i8]* %%message5binary, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1300_count);
  llvm_cbe_tmp__439 = ( char *)(&llvm_cbe_message5binary[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2617
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @charToBinary(i8* getelementptr inbounds ([329 x i8]* @aesl_internal_.str9, i64 0, i64 0), i8* %%1), !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1301_count);
  llvm_cbe_tmp__440 = ( char *)( char *)charToBinary(( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 329
#endif
])), ( char *)llvm_cbe_tmp__439);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__440);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @prep(i8* %%2), !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1302_count);
  prep(( char *)llvm_cbe_tmp__440);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

