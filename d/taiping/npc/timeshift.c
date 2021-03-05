#include <ansi.h>
#include <command.h>

// inherit SMART_NPC;
/*	时辰列表参考

mapping *day_phase = ({
	([	"start_at"	:	0,
		"event_msg"	: 	"你似乎听到三更的梆鼓声。",
		"desc_msg"	:	"夜幕低垂，四周一片暗灰",
	]),
	([	"start_at"	:	240,
		"event_msg"	: 	"东方的天空中逐渐出现了一丝鱼肚白。",
		"desc_msg"	:	"东方的天空浮着一丝淡白色",
	]),
	
	([	"start_at"	:	360,
		"event_msg"	: 	"东方的天空越来越亮，渐渐出现红色。",
		"desc_msg"	:	"红霞在东方的地平线上浮动",
	]),
	([	"start_at"	:	480,
		"event_msg"	: 	"天光似乎越来越垂直了。",
		"desc_msg"	:	"百鸟开始此起彼伏地啼鸣，已经到上午了",
	]),
	([	"start_at"	:	660,
		"event_msg"	: 	"气温逐渐增高，似乎已经是正午了。",
		"desc_msg"	:	"正午到了，忙碌的世界似乎安静了一些",
	]),
	([	"start_at"	:	900,
		"event_msg"	: 	"光线开始慢慢地偏西。",
		"desc_msg"	:	"树荫似乎开始偏往东方了",
	]),
	([	"start_at"	:	1080,
		"event_msg"	: 	"晚霞将西方的天空映成一片火红。",
		"desc_msg"	:	"一带红红的云霞正徘徊在西方的地平线上",
	]),
	([	"start_at"	:	1260,
		"event_msg"	: 	"苍白的大地终于完全吞没了最后一丝光亮。",
		"desc_msg"	:	"夜幕笼罩，周围渐渐隐入了黑暗中",
	])
});

*/


void time_greet(object ob); 

void shifting(object me) {
	
	object ob, start_room,end_room;
	mixed *current_time;
	string my_position, *type;
	int i;
	
	mapping shift_msg = ([
	"day_arrive"		: "$N笑呵呵地走过来说：“今天，这个，天气真好。“\n",
	"day_leave" 		: "$N匆匆忙忙地离开了。\n",
	"night_leave"		: "$N探头看了看天色，随即慢慢走了出去。\n",
	"night_arrive"		: "$N一声不响地走了过来。\n",
	"dinner_leave"		: "$N伸了个懒腰说：“吃饭的时间到喽。“\n",
	"dinner_arrive"		: "$N走过来在桌旁坐了下来。\n",
	"after_dinner"		: "$N心满意足打了个饱嗝，走出了门。\n",
	"back_dinner"		: "$N踱着方步晃了过来。\n",
	]);
	          
	ob=this_object();
	current_time=NATURE_D->get_current_time();
	
	if( !me || environment(me) != environment() ) return;
	if (ob->is_fighting()) return;

//	setting up default routine messages
        type=keys(shift_msg);     
        for (i=0;i<sizeof(type);i++) {
               if (this_object()->query("shift/"+type[i]))
			shift_msg[type[i]]=this_object()->query("shift/"+type[i]);                               
        }      

	
	my_position=file_name(environment(ob));

//	check to see if the NPC has dinner routine: hehe, 事实上是lunch.
	if (ob->query("dinner_room")) {
		if (current_time[5]<800 && current_time[5]>600)
		if (my_position==ob->query("day_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("dinner_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("dinner_room")); 
			message_vision(shift_msg["dinner_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["dinner_arrive"],ob);
			time_greet(ob);
		}
		if (current_time[5]>800 || current_time[5]<600)
		if (my_position==ob->query("dinner_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("day_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("day_room")); 
			message_vision(shift_msg["after_dinner"],ob);
			ob->move(end_room);
			message_vision(shift_msg["back_dinner"],ob);
			time_greet(ob);
		}
	}

//	check to see if the NPC has night routine	
	if (ob->query("night_room"))  {
		if (current_time[5]<240||current_time[5]>1080)
		if (my_position==ob->query("day_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("night_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("night_room")); 
			message_vision(shift_msg["night_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["night_arrive"],ob);
			time_greet(ob);
		}
	
		if (current_time[5]>=240 && current_time[5]<=1080)
		if (my_position==ob->query("night_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("day_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("day_room")); 
			message_vision(shift_msg["day_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["day_arrive"],ob);
			time_greet(ob);
		}
	}

}


void time_greet(object ob) {
	object *inv;
	int i;
	
	inv=all_inventory(environment(ob));
	if (sizeof(inv)<=1) return;
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==ob) continue;
		if (!inv[i]->is_character()) {
			command("hmm "+inv[i]->get_id());
			break;
		}
		command("greet "+inv[i]->get_id());
		break;
	}
	
}