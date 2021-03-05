inherit ITEM;
void create()
{
        set_name("三清道术", ({ "necromancy_book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"三清道术镇教秘籍                        
\n"                );
                set("value", 260);
                set("material", "paper");
        }
    ::init_item();
}
void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
	int sena;
	int cps;
	string book;
        me = this_player();
	cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：study <书> <神数量>\n");
        if( (string)book != "necromancy_book")
                return notify_fail("你要读什麽？\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("你要读什麽？\n");
	tell_object(this_player(),"这居然是本无字天书！！\n");

	return 1;
}
