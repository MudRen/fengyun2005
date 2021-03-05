inherit ROOM;
#include <ansi.h>
void guard_out(object me);

void create()

{
        set("short", "后院");
        set("long", @LONG
后院不大，有一半堆满了稻草，足有一人多高，通往屋子的门紧紧地闭着，几
扇窗户用白纸蒙的严严实实，似乎是怕人窥测。院墙不高，上面长满了爬藤。几只
麻雀在地上蹦蹦跳跳地寻食吃。
LONG
        );
        set("exits", ([ 
			]));
        set("objects", ([
	]) );
	set("item_desc", ([
                "稻草": "稻草很乱，似乎是急急忙忙盖上去的，下面好像有东西在蠕动。\n",
                "straw": "稻草很乱，似乎是急急忙忙盖上去的，下面好像有东西在蠕动。\n",
                "daocao": "稻草很乱，似乎是急急忙忙盖上去的，下面好像有东西在蠕动。\n",
                "麻雀": "几只麻雀在地上蹦蹦跳跳地寻食吃。\n",
                "bird": "几只麻雀在地上蹦蹦跳跳地寻食吃。\n",
                "sparrow": "几只麻雀在地上蹦蹦跳跳地寻食吃。\n",
                "door": "门关着，不知是否你可以打开(open)，不过，里面的人发现了可不会对小偷客气。\n",
                "门": "门关着，不知是否你可以打开(open)，不过，里面的人发现了可不会对小偷客气。\n",
                "院墙":	"墙不高，抓着爬藤可以爬出去。\n",
                "爬藤":	"墙不高，抓着爬藤可以爬出去。\n",
                "vine":	"墙不高，抓着爬藤可以爬出去。\n",
                "wall":	"墙不高，抓着爬藤可以爬出去。\n",
        ]) );
	
	set("spider_out",0);
	set("coor/x",80);
        set("coor/y",75);
        set("coor/z",0);
	set("map","eren");
	setup();
	
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_search","search");
	add_action("do_look","look");
	add_action("do_open","open");
	add_action("do_listen","listen");
}

int do_listen(){
	tell_object(this_player(),"屋中似乎有人窃窃私语，可惜听不太清楚。\n");
	return 1;
}

int do_climb(string arg)
{
   	object me, room;

   	me = this_player();
   	if(!arg || (arg != "wall" && arg !="院墙" && arg!="vine" && arg!="爬藤")){
   		tell_object(me,"你要向哪儿爬？\n");
   		return 1;
   	}
   	
   	if (me->is_busy()|| me->is_fighting()) {
   		tell_object(me,"你现在没空爬墙。\n");
   		return 1;
   	}
   	message_vision("$N抓住藤萝，慢慢地从院墙上爬了出去。\n\n", me);
	call_out("climb_out",3,me);
	me->start_busy(2);
   	return 1;
}

void climb_out(object me) {
	object room;
   	if (me->is_ghost()) return;
   	room = find_object(__DIR__"groad3"); 
   	if(!objectp(room)) room=load_object(__DIR__"groad3");
      	me->move(room);
    message("vision",me->name()+"从院墙上翻了过来。\n", environment(me), me); 
    return;
}

int do_search(string arg) {
	object me, man, ouyang;
	
	me=this_player();
	if(!arg || (arg != "straw" && arg !="daocao" && arg !="稻草")){
		tell_object(me,"搜索那个东西？\n");
   		return 1;
   	}
   	if (me->is_busy()) {
   		tell_object(me,"你现在正忙。\n");
   		return 1;
   	}
   	if (ouyang = present("ouyang ding",this_object())) {
		tell_object(me,"开玩笑吧，主人就在面前。\n");
		return 1;
	}
   	if (query("spider_out")) {
   		message_vision("$N胡乱地将稻草拨开，下面露出一个大缸。掀起缸，里面空空如也。\n",me);
   		return 1;
   	}
	message_vision("$N胡乱地将稻草拨开，下面露出一个大缸。掀起缸，里面是一个穿着黑色紧身衣的人。\n",me);
	man = new(__DIR__"npc/spider");
	man->move(this_object());
	call_out("spider",2,me);
	me->start_busy(2);
	return 1;
}


void spider(object me) {
	object man;
	if (man=present("spiderman",this_object())) {
	call_out("event2",2,me);
	set("spider_out",1);
	me->start_busy(3);
	}
}

string *event2_msg=	({
	CYN"黑衣人一拱手：“大恩不言谢，在下黑蜘蛛，来日定当报答。”\n"NOR,
	CYN"“恶人谷貌似平和，实伏杀机，昨日小弟暗中追随哈哈儿到铁像处失了踪影，踏看时
却失手被欧阳兄弟擒住，若非大侠相助，恐再无生理。”\n"NOR,
	CYN"“据小弟数日踏勘所得，恶人谷下似另有通道，入口便在燕大侠铁像之处。”\n"NOR,
	CYN"“山高水长，就此别过，若有差遣，可至萍姑处寻我。”\n"NOR,
	BLU"黑蜘蛛说罢，突然一扬手，只见他袖管中仿佛有条闪闪发光的银丝，笔直飞了出去，
接着手一抖，人已跟着飞了出去，就像是箭一般的不见了，那银丝也不见了。\n"NOR,
	});


void event2(object me, int count)
{
	object man;
	if (environment(me)!=this_object()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))
	{
		if (man=present("spiderman",this_object())) 
			destruct(man);
		if (!REWARD_D->riddle_check(me,"小村神医") && !REWARD_D->check_m_success(me,"小村神医"))
			REWARD_D->riddle_set(me,"小村神医",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

void reset()
{
     	::reset();
       	set("spider_out",0);
} 

int do_look(string arg)
{
   	object me, room, ouyang;

   	me = this_player();
   	if(!arg || (arg != "window" && arg !="窗户"))
   		return 0;
   	if (ouyang = present("ouyang ding",this_object())) {
		message_vision("欧阳丁大喝一声：干什么！\n",me);
		return 1;
		}
   	message_vision("$N轻手轻脚地走到窗下。\n\n", me);
	if (query("showing")) {
		tell_object(me,"好像已经有人在窗下偷听了耶。\n");
		return 1;
		}
	message_vision("忽然，屋里传出话音，$N赶忙俯下身去。\n\n",me);
	call_out("event1",3,me);
	set("showing",1);
	me->start_busy(2);
   	return 1;
}

string *event1_msg=	({
	CYN"“近几天谷中生人很多，上座要我们小心从事，不要露了痕迹。”\n"NOR,
	MAG"“不妨，有小哈在外面应付，足以让他们忙上一阵。”\n"NOR,
	CYN"“嘿嘿，哈哈儿真有一手，几句好话就把人差遣的团团转。”\n"NOR,
	MAG"“没错，就算他们回来，咱们大事已成了八分，哈哈，哈哈。。。。。”\n"NOR,
	CYN"“后院的那个如何处置？”\n"NOR,
	MAG"“杀，此事关系重大，不能留活口。”\n"NOR,
	CYN"“燕南天这狗贼把我们害的好苦，放着白花花的银子不能花，却要磨什么狗屁豆腐。”\n"NOR,
	MAG"“再忍几天吧，这次事成，还怕没咱兄弟的好日子过？”\n"NOR,
	CYN"“下一批货什么时候往洞里送？”\n"NOR,
	MAG"“嘘，小心隔墙有耳，。。。。。。。。。”\n"NOR,
	BLU"声音越来越低，脚步声慢慢远去了。\n"NOR,
	});


void event1(object me, int count)
{
	if (!me || environment(me)!=this_object()) {
		delete("showing");
		return;
	}
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		delete("showing");
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int do_open(string arg) {
	
	object me;
	object ouyang;
	if (!arg || (arg!="door" && arg!="门")) 
		return 0;
	me = this_player();				
	if (me->is_busy())	{
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
	message_vision("$N轻手轻脚地走到门边，伸手向门板推去。\n",me);
	if (query("showing")){
		message_vision("不过什么也没有发生。\n",me);
		return 1;
	}
		
	if (ouyang = present("ouyang ding",this_object())) {
		message_vision("欧阳丁大喝一声：干什么！\n",me);
		return 1;
		}
	
	message_vision(HIR"突然，哐的一声，门后面的铃响了。\n"NOR,me);
	guard_out(me);
	return 1;
}

void guard_out(object me) {
	object guard;
	if (!guard = present("ouyang ding",this_object()))
	{
		guard = new(__DIR__"npc/ouyang1a");	
		message_vision("欧阳丁突然出现在你面前。\n",me);
		message_vision("欧阳丁喝道：光天化日，竟敢上门行窃！。\n",me);
		guard->move(this_object());
		guard->kill_ob(me);
	}
	return;
}		
