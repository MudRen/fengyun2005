inherit ITEM;
string box();

void create()
{
        set_name("樟木镶金箱", ({ "woodcase"}) );
        set_weight(50000); 
	set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("unit", "个");
                set("long", (: box() :));
                set("value", 1);
                set("closed",1);
        }
	::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
	add_action("do_look","look");	 
}

int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "woodcase" ) return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N“嘎吱”一声，将$n打开了。。。\n", me, ob);
		ob->set("closed",0);
        return 1;
}

int	do_look(string arg) {
	if (!arg || (arg != "woodcase"  && arg!= "樟木镶金箱"))
		return 0;
		
	if (query("closed"))
		write( "
    一口极为珍贵的樟木镶金箱，八只角上，都包着黄金，锁环也是黄金
的。箱子虽有锁，却未锁上。\n");
	else
		write("
    一口极为珍贵的樟木镶金箱，八只角上，都包着黄金，锁环也是黄金
的。箱子虽有锁，却未锁上。
    这箱子里装的竟是个活人。一个几乎是完全赤裸的女人！那女子白羊
般的身子蜷曲在箱子里，看来曲线是那么柔和，胴体是那么丰满，肌肤是
那么晶莹。她胸膛还在微微起伏着，但眼睛却是闭着的，美丽的脸上却带
红晕，像是在沉睡中，又像是晕迷不醒。
	\n");
	return 1;
}