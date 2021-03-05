//uudecode, chitchat, 8/8/1999
//inherit F_ERA;

protected buffer ch = allocate_buffer(1);
protected buffer ch0 = allocate_buffer(1);

/* Single character decode.     */
#define DEC(Char) (((Char) - ' ') & 0x3F)

int main(object me, string arg)
{
        string buf, buf1, infile, outfile;
        int fsize, c, p, n, Nline=1, Nout=0, Nin=0, append=0;
        
        if(!arg){
                write("syntax: uudecode infile [outfile]\n");
                return 1;
        }
        if(arg[0]=='+') {
                append = 1;
                sscanf(arg, "+%s", arg);
        }
        n=sscanf(arg, "%s %s", infile, outfile);

        seteuid(geteuid(me));
        infile = resolve_path(me->query("cwd"), ((n!=2) ? arg : infile));
        fsize = file_size(infile);
        buf=read_file(infile, Nline++, 1);
        if(!buf || sscanf(buf, "begin %s %s\n", arg, buf1)!=2){
                write(infile + " is not of uuencode format!\n");
                return 1;
        }
        Nin += sizeof(buf);
        
        if(n!=2) outfile = buf1;
        outfile = resolve_path(me->query("cwd"), outfile);
        write("Decoding ... this might take a while ...\n");
        if(append){
                n = file_size(outfile)/45;
                Nline += n;
                Nout += n*45;
        }
        else rm(outfile);
        while(1){
                if( (n=fsize-Nin) >= 80) n=80;
                if(n==0) break;
                buf = read_bytes(infile, Nin, n);
                if(!buf) {write("file read error!\n"); break;}
                if( (n=strsrch(buf, '\n')) != -1){
                        buf = read_bytes(infile, Nin, n+1);
                }
                
                Nin += sizeof(buf);
                reset_eval_cost();
                p = 0;
                n = DEC (buf[p]);
                if (n <= 0) break;
                if (strcmp(buf, "end\n")==0) break;
                for (++p; n > 0; p += 4, n -= 3){
                        if (n >= 3) {
                                c = DEC (buf[p+0]) << 2 | DEC (buf[p+1]) >> 4;
                                if(c%256){
                                        ch[0] = c;
                                        write_buffer(outfile, Nout++, ch);
                                }
                                else write_buffer(outfile, Nout++, ch0);
                                c = DEC (buf[p+1]) << 4 | DEC (buf[p+2]) >> 2;
                                if(c%256){
                                        ch[0] = c;
                                        write_buffer(outfile, Nout++, ch);
                                }
                                else write_buffer(outfile, Nout++, ch0);
                                c = DEC (buf[p+2]) << 6 | DEC (buf[p+3]);
                                if(c%256){
                                        ch[0] = c;
                                        write_buffer(outfile, Nout++, ch);
                                }
                                else write_buffer(outfile, Nout++, ch0);
                        }
                        else {
                                if (n >= 1) {
                                        c = DEC (buf[p+0]) << 2 | DEC (buf[p+1]) >> 4;
                                        if(c%256){
                                                ch[0] = c;
                                                write_buffer(outfile, Nout++, ch);
                                        }
                                        else write_buffer(outfile, Nout++, ch0);
                                }
                                if (n >= 2) {
                                        c = DEC (buf[p+1]) << 4 | DEC (buf[p+2]) >> 2;
                                        if(c%256){
                                                ch[0] = c;
                                                write_buffer(outfile, Nout++, ch);
                                        }
                                        else write_buffer(outfile, Nout++, ch0);
                                }
                        }
                }
        }
        write("File " + outfile + " is uudecoded from " + infile + " !\n");
        return 1;
}

