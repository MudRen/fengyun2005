inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "蚌普寺");
        set("long", @LONG
蚌普寺是一世噶玛巴﹒都松钦巴于一一四四年创建的。寺院依山俯水，风景如
画。寺内存有一世都松钦巴自塑雕像一尊，大师生前留下的手迹，鼻血岩画令人肃
然起敬。在秀丽的桑堆河中，游鱼成群，该寺僧人常用手抚摸鱼背，喂以糌粑。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"wild5",
		
	]));
        set("item_desc", ([
        	"鼻血岩画":	"都松钦巴生前留下的手迹。\n",
        	"picture":	"都松钦巴生前留下的手迹。\n",
        	"岩画":		"都松钦巴生前留下的手迹。\n",
    	]));
        
        set("objects", ([
        	__DIR__"obj/statue4":	1,
        	__DIR__"obj/river":	1,
        	__DIR__"npc/monk4":	1,
	]) );
         set("resource/water", 1);
    	set("liquid/container", "桑堆河");  
    	set("liquid/name","桑堆河水");
    	
        set("coor/x",-1800);
        set("coor/y",720);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void reset()
{
	object statue,incense;
               
    ::reset();
   		
   	set("scepter",1);
   		
    statue = present("statue", this_object());
    if (!present("incense",statue)) {
      	incense=new(__DIR__"obj/incense");
    	incense->move(statue);
	}
}

void fish_notify(object obj){
   	object me/*, room, fish*/, *inv, bait;
	int i;
	
   	me = this_player();
	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
     		tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");		
		return;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      			message_vision("$N挥动了一下," + obj->name() + "在空中划了一道漂亮的弧线, 鱼钩落入了水中. \n" , me);
      			me->start_busy(5);
      			remove_call_out("do_fishing");              
      			call_out("do_fishing", 5, me, bait);			
			return;
		} 
	}
   	tell_object(me, "你用的饵不太对吧 ? \n");			
	return;
}

void do_fishing(object me, object bait){
	object 	fish;
	int n;
   	if(me && environment(me) == this_object()) {
   		message_vision("$N很快又扯动了一下鱼杆, " , me);
   		switch (random(10)) {
      			case 0:
      			case 1:
      			case 2:
      			case 3:    	message_vision("却什么都没钓上来 ! \n", me);
         					break;
      			case 4:
      			case 5:
      			case 6:    	message_vision("不但什么都没钓上来，鱼饵倒被鱼吃了 !!  \n", me);
							destruct(bait);				
         					break;
      			case 7:
      			case 8:
      			case 9:		if (!bait->query("fish_bait_zanba")){        
	         					message_vision("什么都没钓上来, 鱼饵一动没动 !!  \n", me);
								destruct(bait);				
         						break;
	         				}	
	         			if (REWARD_D->riddle_check(me,"神偷天下")==2)	n = 1;
	         				else n = 5;
	         			if (random(n) || !query("scepter")) {      				
	         				message_vision("鱼钩上钓到了一条大鱼！！！  \n", me);
	         				fish = new(__DIR__"obj/fish");
	         				fish->move(me);
         				} else {      
	        				message_vision("鱼线往下一沉，似乎钩到了什么重物 ！！  \n", me);
         					message_vision("$N费劲地把鱼竿拉了上来。\n",me);
         					fish = new(__DIR__"obj/t_item4");
         					fish->move(me);
         					set("scepter",0);
         				}
         				destruct(bait);
         				break;
      		}
   	}
	return;
}


void 	init(){
	add_action("do_around","around");
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
	
	if (me->query("marks/转经") ||
		REWARD_D->riddle_check(me,"灵童转世")!=1
		|| me->query_temp("zhuanjing/bangpu"))	return 1;
		
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n你在"+ query("short")+"转经完毕，对密宗佛法的了解略有提高。\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/bangpu",1);
		
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
	
	