inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "塔公寺");
        set("long", @LONG
塔公寺结构奇特，古朴庄重，四周分别建有白、黄、红、绿四塔，塔内长灯彻
夜不息。四方塔周围百余座造型各异的塔林环抱寺庙，寺内正殿供奉着花教创始人
薛迦班智达的塑像，右侧专殿供奉着相传文成公主入藏时所带的“塔公觉巫”。也
许是年代太旧的缘故，寺内香火稀少，建筑已经颇为破落。
LONG
        );
        set("exits", ([ 
		"northup" : __DIR__"mount2",
		
	]));
	set("item_desc", ([
        	"tower": 	"砖塔共有四座，分别为白、黄、红、绿四色。\n",
        	"塔公觉巫": 	"砖塔共有四座，分别为白、黄、红、绿四色。\n",
        	"塔林": 	"砖塔共有四座，分别为白、黄、红、绿四色。\n",
        	"red tower":	"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        	"yellow tower": "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        	"white tower":	"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        	"白塔":		"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        	"黄塔":		"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        	"红塔":		"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
    	]));
	
        set("objects", ([
        	__DIR__"npc/monk2":	1,
        	__DIR__"obj/statue2":	1,
	]) );
        set("coor/x",-1700);
        set("coor/y",590);
        set("coor/z",15);
	set("map","zbwest");
        set("item",1);
	setup();

}

void init(){
	add_action("do_look","look");
	add_action("do_around","around");
}

int do_look(string arg) {
	object me=this_player();
	object item;
	
	if (arg== "hole" || arg == "浅穴") {
		if (!me->query_temp("zangbei/塔公寺砖塔")) 
			return notify_fail("你要看什么？\n");
			if (me->query("kar")< 12)
				return notify_fail("你伸手进去摸索了一阵，一不小心抓到一堆鸟粪，唉，运气太坏了！\n");
         	if (query("item")) {
				tell_object(me,"孔不深，你伸手进去摸索了一阵，拿到一件硬硬的东西。\n");
				if (random(3))
					item = new(__DIR__"obj/t_item2");
				else
					item = new(__DIR__"obj/annie_item");
         		        		
         		item->move(me);
         		set("item",0);
         	} else 
         		tell_object(me,"孔不深，你伸手进去摸索了一阵，里面是空的。\n");
		return 1;
	}
	if (arg == "green tower" || arg == "绿塔") {
		tell_object(this_player(),"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",);
		if (!me->query_temp("zangbei/塔公寺施舍")) 			
			return 1;
		tell_object(me,"仔细看去，正如老喇嘛所说，塔基的砖石已经非常松散，许多地方甚至少了几块，
露出几个浅穴（ｈｏｌｅ）。\n");
		me->set_temp("zangbei/塔公寺砖塔",1);
		return 1;
	}
	return 0;
}


void reset(){
	set("item",1);
	::reset();
}


int do_around(){
	
	object me = this_player();
	object tong = me->query_temp("weapon");
	
	
	if (!tong || tong->name() != "转经筒")
		return notify_fail("没有经筒，如何转经？\n");
	
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空转经。\n");
				
	message_vision(YEL"$N转动着手中的小经筒，虔诚地颂着经文，绕着"
		+this_object()->query("short") + "慢慢走了一圈。\n"NOR, me);
	me->start_busy(1);
	
	if (me->query("marks/转经")
		||	REWARD_D->riddle_check(me,"灵童转世")!=1
		|| me->query_temp("zhuanjing/tagong"))	return 1;
		
	me->add_temp("zhuan_around",1);
		
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n你在"+ query("short")+"转经完毕，对密宗佛法的了解略有提高。\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/tagong",1);
		
		if (mapp (me->query_temp("zhuanjing")))
		if (sizeof(me->query_temp("zhuanjing")) == 4)
		{
			REWARD_D->riddle_set(me,"灵童转世",2);
			me->set_skill("lamaism",me->query_skill("lamaism",1)+1);
			tell_object(me,HIC"你的密宗佛法提高了一个等级。\n"NOR);			
			me->set("marks/转经",1);
			me->delete_temp("zhuanjing");
		}
	}
	return 1;
}
	
	