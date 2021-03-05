#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "风云衙门");
        set("long", @LONG
这里是朝廷所设，附近城里的纠纷都可以在这里上状请求处理。大厅南首一张
卷檐木案，案上有个小竹桶，里面插着几根有知府官印的竹签。木案后的太师椅上
铺着雪绒皮，椅后屏风上红日青云图。上悬金边匾：
[0;1;33m
				明察秋毫
[0m
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
        	"north" : __DIR__"street5",
        	"south" : __DIR__"shufang",
        	"west" : __DIR__"w_xiangfang",
        	"east" : __DIR__"e_xiangfang",
    	]));
    	set("objects", ([
		__DIR__"npc/yayi0" : 1,
        	__DIR__"npc/yayi1" : 2,
        	__DIR__"npc/yayi" : 2,
        	__DIR__"npc/yayi2" : 2,
    	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}

/*
void init()
{
	object xing;
	mixed *current_time;
	
	add_action("do_arrest","arrest");	
	if (!interactive(this_player()))	return ;
		
	current_time=NATURE_D->get_current_time();
	if(xing=present("xing rui",this_object()))
	{
		if(current_time[5]<480||current_time[5]>1200)
		{
			message_vision(CYN"邢锐忽然有如大梦初醒一般，说道：“原来都这么夜了，是回家的时候了。”\n"NOR,xing);
			message_vision(CYN"邢锐慢慢的走了出去。\n"NOR,xing);
			destruct(xing);
		}
		else if(current_time[5]>1080)
		{
			message_vision(CYN"邢锐拍拍肩膀说道：“太晚了，有事明天再来吧。”\n"NOR,xing);
			message_vision(CYN"邢锐自言自语道：“去和江师爷喝两盅吧。”转身离开。\n"NOR,xing);
			destruct(xing);
		}
	}
	else
		if(current_time[5]>480&&current_time[5]<960)
		{
			xing=new(__DIR__"npc/xing");
			xing->move(this_object());
			message_vision(YEL"邢锐低声的说道：“升～～～～堂～～～～”\n"NOR,xing);
		}
	
}

int do_arrest(string arg)
{
	
	object me, target,xing;
	int exp, stra,leader,factor,mysen;
	if(!arg)
		return notify_fail("你要下令缉拿谁？\n");
	me = this_player();
	if((string) me->query("class") != "official" )
		return notify_fail("你不是朝廷官员，不可缉拿疑犯！\n");
	if (me->query("marks/官府/岳飞"))
        	return notify_fail("你是指挥千军万马的大将，抓犯人的事还是留给管律法的官员去做吧。\n");
	
	xing = present("xing rui",this_object());
	
	if(!xing ) 
		return notify_fail("总捕头不在，无法下令拘捕犯人。\n");
	mysen=(int) me->query("sen");
	if( mysen< 150 )
		return notify_fail("你的心神不够！无法下拘捕的命令。\n");	
	if (me->is_busy())
		return notify_fail("你现在没空！！\n");
	
	if(!objectp(target = find_living(arg)))
		return notify_fail("邢总捕头对你说道：“小人无能，没有关于这个人的线索，无法拘捕。”\n");
	if( !userp(target) && !environment(target))
		return notify_fail("邢总捕头对你说道：“小人明察暗访，此人似乎已潜伏起来了，找不到线索，等些时候再说吧。”\n");
	if( userp(target) || !environment(target))
		return notify_fail("邢总捕头对你说道：“请恕小人多言，此人并无过犯，还是得饶人处且饶人吧。”\n");
	if( target->query("no_arrest") )
		return notify_fail("邢总捕头叹了口气说：“此人所在之处不属官府管辖范围，有心擒贼，无力回天啊。”\n");
	if (target->is_fighting())
		return notify_fail("邢总捕头沉思片刻说：此人已经有仇家找上门了，我们且静观其变。\n");
	if (target->is_vendor()|| target->query("fly_target"))
		return notify_fail("邢总捕头难为地说：拘捕此人不难，只是恐怕会有许多不便之处。\n");
	if (environment(target)==this_object())
		return notify_fail("邢总捕头得意地说：小人已经把此人拘拿归案了。\n");		
		
	mysen=mysen*3/100;
	me->add("sen",-mysen);
	
	message_vision("$N大声下令道：来人那．．把$n给我拿来！！\n",me,target);
	message_vision("$N说道：“捕快何在？还不快去执行"+me->query("name")+"大人的命令！！。\n",xing);
	
	exp = (int) target->query("combat_exp");
	stra = (int) me->query_skill("strategy",1);
	leader = (int) me->query_skill("leadership",1);
	factor = stra * stra / 10 * leader / 10 * leader / 10;
	factor += ((int) me->query("combat_exp") - 2000 )/1000;			
	if( random(factor) <= exp) {
		me->start_busy(3);
		return notify_fail("邢总捕头对你说道：“小人无能，让"+target->query("name")+"逃脱了！\n");
	}
	
	me->start_busy(2);
	call_out("gethim",5,target,me);
	return 1;
}

int gethim(object target,object me)
{
	if(!target || !me ) return 1;
	if (target->is_fighting()) {
		tell_object(me,"邢总捕头对你说道：“小人无能，让"+target->query("name")+"逃脱了！\n");
		return 1;
	}
	if(environment(me) == this_object())
	{
        message_vision("忽然一群捕快冲了过来，二话不说就将$N铐走了。\n",target);
        target->move(this_object());
        message_vision("$N被官兵押了进来。\n",target);
	if(me){
	me->kill_ob(target);
	target->kill_ob(me);
	target->start_busy(3);
		}
        return 1;
	}
	return 1;
}

valid_leave(object me,string dir)
{
	object xing;
	
	if((dir =="south" || dir == "west") && me->query("class")!="official"
		&&xing=present("xing rui",this_object()))
		return notify_fail("邢锐对你喝道：“不得擅闯机要重地！！”\n");
	return 1;
}


void reset(){
	object *inv, *npc;
	int num, i;
	string id;
	inv = all_inventory(this_object());
	npc = filter_array(inv,(: living($1) && !userp($1):));
	num = sizeof(npc);
	for (i=0; i<num; i++) {
		id = npc[i]->query("id");
		if ( npc[i]->is_corpse() || id =="yayi"
			|| id=="chaiyi" ||  id == "xing rui"
			|| !npc[i]->query("startroom")) continue;
//		npc[i]->ccommand("say 萨有纳拉！！");
		npc[i]->return_home(npc[i]->query("startroom"));
	}
	:: reset();
}

*/		