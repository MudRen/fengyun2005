#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乱葬冈");

	set("long", @LONG
这里是附近百姓们谈之色变的乱葬冈，齐人高的野草在阵阵阴风中摇摆不定，
周围密密麻麻地堆了好几十个坟头。但看上去都很久没有人祭祀，墓碑东一块，西
一块倒在地上，一副破败不堪的景象。
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"southeast":__DIR__"tomb3",
	]) );
	set("objects", ([
                __DIR__"obj/daocaoren" : 1,
        ]) );
        set("item_desc", ([
		"paper": "一张写了几个字的纸条。天色很黑，看不清楚写的什么。看来只好撕(tear)下来看了.\n"
	])); 
	set("in_action",0);
	set("coor/x",-60);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_tear","tear");
}

int do_tear(string arg)
{	
	object me,paper;
	int dodge;
	
	if (!arg ||(arg != "纸条" && arg != "paper")) 
		return notify_fail("你要撕什么东西？\n");
	me=this_player();
	dodge=me->query_skill("dodge",1);
	if (query("in_action")==1)
		return notify_fail("有人已经在撕纸条了。\n");
	if (query("in_action")==2) 
		return notify_fail("纸条已经被人撕走了。\n");
		
	message_vision(HIW"\n$N伸手将纸条撕了下来．．．．\n\n"NOR,me);
	set("in_action",1);
	message_vision(HIY"\n稻草人突然动了一下，手中的哭丧棒自上而下向$N直击下来。\n\n"NOR,me);
	if (dodge<20)
	{
		message_vision(HIR"\n$N面对突如其来的袭击，目瞪口呆，不知所措．．．．\n\n"NOR,me);
		message_vision(HIR"\n结果，$N被哭丧棒打成一滩肉泥．．．．\n\n"NOR,me);
		me->die();
	}
	else
	{
		message_vision(HIR"\n$N面对突如其来的袭击，不慌不忙，向后倒跃数尺．．．．\n\n"NOR,me);
        	message_vision(HIR"\n哭丧棒从$N面前直掠而下．．．．\n\n"NOR,me);
		paper=new(__DIR__"obj/paper");
		paper->move(me);
		me->start_busy(5);
		if (me && environment(me) == this_object())
		{
			call_out("shoot_me", 3, me);
		}
		else
			remove_call_out("shoot_me");
	}
	return 1;
}

void shoot_me(object me)
{
	int dodge;
	int kee;
	
	dodge=me->query_skill("dodge",1);
	kee=(int) me->query("max_kee")/3;
	message_vision(HIY"\n突然一片乌光从稻草人手中哭丧棒的棒头飞出，直射$N。\n\n"NOR,me);
	if(dodge<60)
	{
		message_vision(HIR"\n$N闪避不开，被射个正着．．．．\n\n"NOR,me);
		me->receive_wound("kee", kee);
	}
	else
	{
		message_vision(HIW"\n$N镇定异常，轻笑声中，拔地而起，暗器全部落空．．．\n\n"NOR,me);
	}
	message("vision",HIW"稻草人摇摇摆摆着倒了下去，露出一条小路。\n"NOR,me );
	set ("in_action",2);
	if( !query("exits/east") ) 
 	{
		set("exits/east", __DIR__"tomb0");
		call_out("close_path", 20);
	}
	return;
}

void close_path()
{
        if( !query("exits/east") ) 
        	return;
        message("vision",
"一阵风吹过，稻草人摇摇摆摆着恢复原位，又挡住了去路。\n",this_object() );
	delete("exits/east");
	set("in_action",0);
}

void reset()
{

::reset();
	if(query("in_action")) set("in_action",0);
        
} 
