// testshadow.c
inherit F_CLEAN_UP;

int main(object me)
{
        object res,des;
        string err;
        seteuid(ROOT_UID);
        res=new("/obj/misc/topaz");
        res->move(me);
//      res->set("id","test1");
        write(res->query("id")+"\n");
//      des=new("/obj/misc/sword");
	write(sprintf("shadow is %O\n",query_shadowing(this_object())));
//	write(sprintf("shadowed is %O\n",query_shadowed(this_object())));
//      shadow(res);
	err=catch(shadow(res));
//      if(objectp(shadow(res)))
	if(!stringp(err))
                write("shadow ok\n");
	else write("err is "+err+"\n");
	write("done\n");
        return 1;
}

void result()
{
	CHANNEL_D->do_sys_channel("sys",sprintf("现在的所处的环境是->%O\n",environment(this_player())));
}