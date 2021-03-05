//XXDER
inherit ITEM;
void create()
{
        set_name("战书", ({ "letter", "战书"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
				set("long",
"一封信函，似乎可以打开(open)看看。\n"
);
				set("keke",1);
        }
  ::init_item();
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

 
int do_open(string arg)
{
	if (!arg) return notify_fail("你想打开什么？");
	if (arg!="letter") return notify_fail("那个东西不能打开");
	message_vision("$N打开了$p，从中拿出了一封信，上面写着：
日期 ：元夜子时。
地点：贵宅。
兵刃我用飞刀，君可任择。
胜负；一招间可定胜负，生死间亦可定．
挑战人：灵州。薛。\n",this_player(),this_object());
	if (!this_player()->query("marks/偷看可可的信"))
	{
		this_player()->add("score",-100);
		this_player()->set("marks/偷看可可的信",1);
	}
	return 1;
}

