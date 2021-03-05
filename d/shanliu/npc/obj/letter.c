#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("给七个半的信", ({ "letter", "信"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                                set("long",
"一封用火漆封得严严实实的密函，但似乎如果用力地话，仍可以撕开(tear)\n"NOR);
        }
	::init_item();
}

void init()
{
  if(this_player()==environment()){
	add_action("do_tear","tear");

	}
}

int do_tear(string arg)
{
	object		me, ob;
        if(  arg != "letter" )
                return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N将$n的封口撕开，取出了其中的信笺\n", me, ob);
	set("open",1);
	set("long","七个半兄：若此信完好，则持信人当可大用，
可示其去路，若信已毁，则此人不可留用。 无名 谨上\n");
	if (me==query("送东西人"))
	{
		me->set("山流/失败",time());
		me->delete("入山流/取回盟册");
		me->delete("入山流/治愈麻风");
		me->delete_temp("入山流/送东西");
	}
	remove_action("do_tear","tear");
    return 1;
}

