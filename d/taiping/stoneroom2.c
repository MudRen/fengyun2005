inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "地下石室");
        set("long", @LONG
石室的两旁排放着一个一个的箱子。石门的对面也是一面石壁，石壁的正中都
向内凹陷，一丈宽阔。那正中放着一个石坛，之上是一座石像。石像亦是被火焰映
成了碧绿色。刻工相当细致，石像栩栩如生，一张脸更是活灵活现。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"stoneroom",
	]));
	set("no_fly",1);
        set("objects", ([
        	__DIR__"npc/daniang2": 1,
    	]) );
        
        set("item_desc", ([
		"箱子": "箱子形状古雅，雕刻精致，镶金嵌玉，盘龙舞凤，并不像一般富贵人家所有。只看
箱子的表面，已知道价值不菲。这样珍贵的箱子用来装载的又是何等珍贵的东西？\n",
		"box": "箱子形状古雅，雕刻精致，镶金嵌玉，盘龙舞凤，并不像一般富贵人家所有。只看
箱子的表面，已知道价值不菲。这样珍贵的箱子用来装载的又是何等珍贵的东西？\n",
	 ]));
	set("coor/x",110);
	set("coor/y",-30);
	set("coor/z",-20);
	set("map","taiping");
	setup();
}



void init() {
	
	add_action("do_look","look");
}



int do_look(string arg) {

	object me;
	me=this_player();
	
	if (arg=="石像" || arg =="statue") {
		me->start_busy(10000);	
		tell_object(me,"魔中之魔，诸魔之王。魔王！石像正是鹦鹉楼血奴房中那幅魔画上画着的那个头
戴紫金冠，既英俊又温和的年轻魔王。他的眉宇间，凝聚着一种莫名的落寞。\n");	
		
		if (REWARD_D->riddle_check(me,"喋血鹦鹉")!=13 && !REWARD_D->check_m_success(me,"喋血鹦鹉")){
			tell_object(me,"石像似乎晃了晃，你揉揉眼睛，许是看错了。。。\n");
			return 1;	
		}
		me->set_temp("disable_inputs",1);
        me->set("disable_type",HIW "<出神中>" NOR);
		call_out("event1",1,me,0);
		return 1;
	}
	return 0;
}	


string *event1_msg=	({
	HIG"\n\n  魔王悲哀的眼瞳突然流出了眼泪。晶莹的眼泪，碧绿的火光中闪烁着碧绿的光芒。\n",

 	HIG"  碧绿色的泪光。悲哀的眼神，晶莹的眼泪。看得人心都快碎了。\n"NOR,

    	HIG"  泪光闪动，眼睛却并没有变化，一眨也不眨。瞳孔也一动不动，仿佛已凝结。\n"NOR,
	
	HIG"  一双点漆的眼瞳，碧绿的火光照耀下亦已碧绿，猫眼般闪光。\n"NOR,

	WHT"  石像忽然在浮动，就像是烟，就像是雾。\n"NOR,

    	WHT"  不过一刹那，整个石像都烟雾一样散开，消失。\n"NOR,

    	YEL"  站立在石像方才站立的地方，是一个活人。\n"NOR,

	YEL"  紫金白玉冠，英俊而温和，这个人不就是鹦鹉楼血奴房中那幅魔画之上所画着的那
个年轻人吗？十万妖魔群向他膜拜，血鹦鹉展翼向他飞投。魔中之魔，诸魔之王。\n"NOR,

    	HIR"                                 魔王！\n"NOR,

	YEL"  碧绿色的火焰之下，他完全没有碧绿。那种碧绿色的光芒，根本不能落到他的身上。
他的面犹如冠玉，他的手也是一样。他在笑，笑容温柔而高贵。\n"NOR,

        YEL"  魔王竟已看穿了你的心，笑着忽然道：“朕知道你心中有很多问题无法解决。”魔
王接着又道：“你很想知道血鹦鹉的秘密？”他的语声温柔如女子，却又带着一种
难以抗拒的威严。你不知不觉地点头。\n"NOR,

	YEL"  魔王转过身，向左面的石壁走过去。你不由自主地跟在他身后。\n"NOR,


});


void event1(object me, int count)
{
	if (!me)	return;
		
	if (environment(me)!=this_object()) {
		me->delete_temp("disable_inputs");
        me->delete("disable_type");
		return;
	}
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
			tell_object(me,YEL"  魔王脚步不停，竟走入了石壁之内。你硬着头皮，一脚向那面墙壁跨入去。
那只脚竟然轻而易举地一直跨进了墙壁之内。\n\n"NOR);
		me->stop_busy();
		me->delete_temp("disable_inputs");
        	me->delete("disable_type");
        	me->move(AREA_TAIPING"dream1");
        	me->unconcious();
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


