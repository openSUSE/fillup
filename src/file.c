
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Copyrights to S.u.S.E. GmbH Fuerth (c) 1996                                */
/* Copyrights to SuSE GmbH            (c) until 2001                          */
/* Copyrights to SuSE Linux AG        (c) 2002,2003                           */
/*                                                                            */
/* Time-stamp:                                                                */
/* Project:    fillup                                                         */
/* Module:     file                                                           */
/* Filename:   file.c                                                         */
/* Author:     Joerg Dippel                                                   */
/* Description:                                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*--------------------------------- IMPORTS ----------------------------------*/

#include "parser.h"
#include "services.h"
#include "file.h"

/*-------------------------------- FUNCTIONS ---------------------------------*/

/*----------------------------- IMPLEMENTATION -------------------------------*/

/*-------------------- readFile --------------------*/
File_t
readFile 
(
    ParameterSpecification_t    fileSpecifier, /* in */
    const char                * filename       /* in */
)
{
    File_t                      returnValue;
    FILE                      * filePointer;
    long                        fileLength;

    if( FileOpened == openFileForReading( filename, &filePointer ) )
    {
        if( Success == getFileLength( filePointer, &fileLength ) )
        {
            void              * ptr;

            /*
             * Allocate one byte more if a newline must be added
             */
            if( Success == allocateBuffer( fileLength + 1 , &ptr ) )
            {
                char          * buffer = ( char * )ptr;

                if( Success == readFileToBuffer( filePointer, fileLength, &buffer ) )
                {

                    if ( FALSE == queryParameter( IgnoreEOF ) )
                    {
                        char  * eof = (buffer + fileLength - 1);

                        if ( *eof != '\n' )
                        {
                            *( eof + 1 ) = '\n';
                            fileLength++;
                        }
                    }

                    addToWatchdog( fileLength );
                    associateBuffer( fileSpecifier, fileLength, &buffer );
                    returnValue = FileOperationsSuccessful;
                }
                else
                {
                    freeBuffer( &buffer );
                    returnValue = FileOperationsFailed;
                }
            }
            else
            {
                returnValue = FileOperationsFailed;
            }
        }
        else
        {
            returnValue = FileOperationsFailed;
        }
        closeFile( filePointer );
    }
    else
    {
        returnValue = FileOperationsFailed;
    }

    return( returnValue );
}

/*----------------------------------------------------------------------------*/

