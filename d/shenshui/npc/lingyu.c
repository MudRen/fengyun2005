// XXDER

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("方灵玉" , ({ "lingyu", "girl", "ling yu" }) );
	set("long", "窗边床上端坐着一个女孩，美绝人寰的脸上没有一丝表情，一袭黑纱衬
托着如玉的脸庞，一双眼睛犹如夜空灿烂的星星。她似乎陷入了沉思，
又似乎在聆听海涛声，眼光凝视在窗外的某一点。\n\n");
	set("attitude", "friendly");
	
	set("inquiry", ([
		"ocean" : "海是神秘的，传说曾经有一族鲛人居住在那里。\n",
		"海" : "海是神秘的，传说曾经有一族鲛人居住在那里。\n",
		"鲛人": "传说中的蛟人，象鱼儿一样可以在水底自由呼吸。\n",	
		"碧海蓝心":"春江潮水连海平，海上明月共潮生，滟滟随波千万里，何处春江无月明。"		
	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
     name()+"静静地看着窗外的海涛，似乎没有注意到你的存在。\n",
    }) );

	set_skill("parry", 180);
	set_skill("charm", 180);
	set_skill("nine-moon-force",180);
    	    		
	set("age", 14);
	set("gender", "女性" );
	set("per", 30);
	set("combat_exp", 5000);
	setup();
	carry_object(__DIR__"obj/blackcloth")->wear();
}

int answer_react(object me, string arg){
    	object mask;
    	
    	if(arg == "dunno" && !query("given")) {
        	message_vision("\n$N迟疑了一下说道：“海确实是一个神秘的世界，又有谁对那个世界真的了解呢？”\n", me);      
        	message_vision("$N微笑着递给$n一样东西同时说道：“也许那一天你会用到这个。”\n", this_object(), me);
        	mask = new(__DIR__"obj/jiaoxiao"); 
        	set("given",1);
        	me->delete_temp("marks/lingyu_asked");
        	mask->move(me);    
    	} else if(arg == "no"){
        	message_vision("$N拍手大笑说道：“那只不过是个哄小孩子的传说罢了。”\n",me);
        	message_vision("\n$N微微一笑说道：“是么？”，与此同时$N的手似乎微微一动。\n", this_object());
        	me->delete_temp("marks/lingyu_asked");
        	tell_object(me, "\n只觉得一阵掌风袭来，你一个旱地拔葱向后闪开，然而脚下一空，你\n");
        	tell_object(me, "蓦然一惊，身形已从窗口翻了出去。\n");
        	message("vision", "\n" + me->name() + "一个旱地拔葱向后退去，随着一声惊叫身形消失在窗外。\n", 
                environment(me), me);
        	environment(me)->fall_out(me); 
    	} else if(arg == "yes"){
        	message_vision("\n$N道：“我信，沧海月明珠有泪，美丽而多情的蛟人用她们的泪编织海底世界
的神秘瑰丽。”\n", me);
	    	message_vision("$N注视窗外的双目转了过来看了$n一下，一丝笑容浮现在她脸上，你的心
儿不由怦怦地紧跳几下,许久许久说不出一句话。\n", this_object(), me);
    		me->delete_temp("marks/lingyu_asked");
    	}
	return 1;
}
