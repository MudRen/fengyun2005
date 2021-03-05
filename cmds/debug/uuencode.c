//uuencode, chitchat, 8/8/1999
//this is to cat a long file in uuencoded format, useful
//for logging and editing file using mud client

/* here is an example for using vim to edit file under tintin++
/var begin 0
/al nvi {/var begin 1;/log;/log edit.uu;/var filename $0;uuencode $0}
/act {^end} {/if {$begin}{/var begin 0;/log;/sys uudecode -o edit.c edit.uu;/sys vim edit.c;/sys uuencode edit.c $filename > edit.uu;rm $filename.uu;edit $filename.uu;O;/tex edit.uu;.;x;uudecode $filename.uu;rm $filename.uu}}
 * end of sample tintin++ code */

protected string uu_std = "`!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";
/* ENC is the basic 1 character encoding function to make a char printing.      */
#define ENC(Char) (uu_std[(Char) & 0x3F])

int main(object me, string arg)
{
        int c, c1, c2, n, p, offset=0;
        string buf, infile, name;
        string ch = " ";

        if(!arg){
                write("syntax: uuencode realfile [filename]\nOutput will be directly printed for capture.");
                return 1;
        }

        if(sscanf(arg, "%s %s", arg, name)!=2)
                name = arg;
        seteuid(geteuid(me));
        infile = resolve_path(me->query("cwd"), arg);
        write("\nbegin 600 " + name + "\n");
        while (1) {
                n = 0;
                do { //read_bytes cannot exceed the EOF, so ...
                        buf = read_bytes (infile, offset, 45 - n);
                        n++;
                } while (!buf && n<45);
                reset_eval_cost();
                if( (n=sizeof(buf)) == 0 ) break;
                
                offset += n;

                ch[0] = ENC (n);
                write(ch);
                for (p = 0; n > 2; n -= 3, p += 3) {
                        c = buf[p] >> 2;
                        ch[0] = ENC (c);
                        write(ch);
                        c = ((buf[p] << 4) & 0x30) | ((buf[p+1] >> 4) & 0x0F);
                        ch[0] = ENC (c);
                        write(ch);
                        c = ((buf[p+1] << 2) & 0x3C) | ((buf[p+2] >> 6) & 0x03);
                        ch[0] = ENC (c);
                        write(ch);
                        c = buf[p+2] & 0x3F;
                        ch[0] = ENC (c);
                        write(ch);
                }

                if (n != 0) break;

                write("\n");
        }

        while (n != 0)
        {
                c1 = buf[p];
                c2 = n == 1 ? 0 : buf[p+1];

                c = c1 >> 2;
                ch[0] = ENC (c);
                write(ch);

                c = ((c1 << 4) & 0x30) | ((c2 >> 4) & 0x0F);
                ch[0] = ENC (c);
                write(ch);

                if (n == 1)
                        ch[0] = ENC ('\0');
                else {
                        c = (c2 << 2) & 0x3C;
                        ch[0] = ENC (c);
                }
                write(ch);
                ch[0] = ENC ('\0');
                write(ch + "\n");
                break;
        }

        ch[0] = ENC ('\0');
        write(ch + "\n");
        write("end\n");
        return 1;
}


