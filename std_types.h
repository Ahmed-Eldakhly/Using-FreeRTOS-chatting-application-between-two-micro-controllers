/*************************************************
 * Module 	  : Data Types definition
 *
 * File name  : std_types.h
 *
 * Created on : Apr 9, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 *************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*Boolean Data Type*/
typedef unsigned char bool;

/*Boolean Value*/
#ifndef FALSE
#define FALSE  (0U)
#endif

#ifndef TRUE
#define TRUE   (1U)
#endif

#ifndef HIGH
#define HIGH   (1U)
#endif

#ifndef LOW
#define LOW	   (0U)
#endif

#ifndef INPUT
#define INPUT  (0U)
#endif

#ifndef OUTPUT
#define OUTPUT (1U)
#endif

#ifndef I
#define I 	   (7U)
#endif


#ifndef NULL
#define NULL  (0U)
#endif

#ifndef NULL_PTR
#define NULL_PTR  ((void *)0)
#endif

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPES_H_ */
