# Rivest, Shamir and Adleman (RSA) Text File Encryption

An implimentation of RSA encryption of text files using command-line.

Sample of CLI:

```powershell
Please enter the Text. Use <Enter> to finish:
Hi, Alex!

 Text ASCII   CryptoText/Block#  ASCIIdecrypt  Text decrypt
------------------------------------------------------------
    H    72               11960            72             H
    i   105               12744           105             i
    ,    44                3395            44             ,
         32                7200            32
    A    65                 169            65             A
    l   108                7272           108             l
    e   101               15525           101             e
    x   120                1284           120             x
    !    33               14541            33             !
```

## Environment & Dependencies

C++ 11, cross-platform.

## ToDo

* Variable key length
