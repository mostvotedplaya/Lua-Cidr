#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ip2long( const char *addr )
{
    struct in_addr ip;
    if ( inet_pton( AF_INET, addr, &ip ) )
    {
         return ntohl( ip.s_addr );
    }
    return -1;
}

int inCidr( const char *addr, const char *cidr )
{
    if ( strlen( addr ) < 7 || strlen( addr ) > 15 )
    {
         return 0;
    }

    if ( strlen( cidr ) < 9 || strlen( cidr ) > 18 )
    {
         return 0;
    }

    char *tmp1 = strtok((char *) cidr, "/" );
    char *tmp2 = strtok((char *) NULL, "/" );

    if ( tmp1 == NULL || tmp2 == NULL )
    {
         return 0;
    }

    int address = ip2long( addr );
    int network = ip2long( tmp1 );
    int mask    = atol( tmp2 );

    if ( address == -1 || network == -1 )
    {
         return 0;
    }

    if ( mask < 0 || mask > 32 )
    {
         return 0;
    }

    int netmask = pow( 2, ( 32 - mask ) ) - 1;
    int negate  = ~netmask;

    return ( ( address & negate ) == ( network & negate ) );
}
