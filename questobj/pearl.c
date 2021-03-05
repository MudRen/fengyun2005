
inherit ITEM;

void create()
{
	set_name("夜明珠", ({ "lighting-pearl", "pearl"}) );
	set_weight(3);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
	        set("long", @LONG
一颗淡青色的小珠子，在黑暗静静的散发着柔和的光芒，就象是情人的
眼睛。那么的美丽，那么的动人。看着看着，你不禁痴了，是不是也想
起了从前，曾与她一起泛舟于明月之下，曾和她携手漫步在百花之间，
想起了那双给你带来过无穷自信的柔情似水的眼睛。
瞎眼老爹生活如此困苦，却不肯将此珠卖掉，是否这里面也隐藏着一段
故事？
LONG);
		set("value", 10000);
	}
	::init_item();
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "pearl" && arg!="lighting-pearl" ) return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");
        environment(this_player())->light_notify(this_object(), 1);

        return 1;
}


