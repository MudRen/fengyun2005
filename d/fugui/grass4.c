#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "白梅园");

	set("long", @LONG
这里便是白梅园了，平常燕七就最喜欢到这里走走，说是在清雅的梅香中能静
下心想些事情，每逢此时，郭大路定会撇撇嘴，不屑道：一个人的身上穿的若还是
春天的薄衣服，肚子里装的若还是昨天吃的阳春面，他唯一还有心情欣赏的东西就
是可以往嘴里吞下去、塞饱肚子的，决不会是什么梅花。当然梅花若是换成辣椒那
倒可以考虑考虑。秋天的梅树上没什么花，但奇怪的是这里仍飘散着一股清香。
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"woshi1",
		"west":__DIR__"woshi",
		"north":__DIR__"chaifang",
	]) );
	set("item_desc", ([
        "梅树": "梅树上没有花，树干上钉了一块小牌子，年代看来很久远了。\n",
        "tree": "梅树上没有花，树干上钉了一块小牌子，年代看来很久远了。\n",
        "牌子": "牌子上写着-[..动埋....处。]，但是年代久远，有几个字看不清了。\n",
        "paizi": "牌子上写着-[..动埋....处。]，但是年代久远，有几个字看不清了。\n"
        ]) );
	set("coor/x",10);
	set("coor/y",240);
	set("coor/z",80);
	setup();
}

int dig_notify(object obj, int i)
{
	object me,jt;
	int kee;
	int max_kee;
	me = this_player();
	
	if (me->is_busy()){
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
		
	message_vision(YEL"$N手中的"+obj->name()+"碰到坚硬的地面，发出＇叮＇的一声。\n"NOR , me);
	// Enough warning here!
	tell_object(me,YEL"你被震的气喘吁吁，两眼发花，心头狂跳，该歇歇了！\n"NOR); 
	me->receive_damage("kee",(int)me->query("max_kee")/4);
	me->set_temp("last_damage_from","在富贵山庄干活累死了。\n");
	
	if (query("digged")) 
	{
		message_vision("$N辛辛苦苦挖了半天什么也没挖到。\n", me);
    	return 1;
    }
    else
    {
   		switch ( random(3) )
   		{
   	  	case 0: 
   	       	message_vision("$N发现地下似乎有个酒坛子。\n",this_player());
   	       	jt = new(__DIR__"obj/bottle");
			jt->move(this_player());
			set("digged",1);
			message_vision("$N激动地扔掉"+obj->name()+"，连忙捡起"+jt->name()+"。 \n",this_player());
   			destruct(obj);
     		break;
   	  	case 1:
        	message_vision("地上的土被$N翻起一块,没什么发现。\n",obj);
    	  	break;
   		case 2:
    	  	message_vision("锵．．得一声，$N手中的"+obj->name()+"断了。\n",this_player());
   	  		destruct(obj);
     		break;
     	}
 	}
 	me->start_busy(3);
	return 1; 
}


void reset(){
	::reset();
		
	if (!random(5)) set("digged",0);
}

		