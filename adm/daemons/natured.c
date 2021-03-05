// natured.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//		- 08/20/2001 by Daniel Q. Yu.
//			* put in weather system.

// We assume that our FengYun calendar is:
//		12 monthes per year
//		30 days per month
//		12 时辰 (2 hours) per day
//		4 刻 (30 mins) per 时辰 
//		One min game == one sec real time.
//		Max year is about 4000 years (due to time() function)

#include <ansi.h>

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

mapping *year_phase = ({
	([	"month"		: 	1,
		"day"		:	1,
		"event_msg"	:	"新的一年到了，到处都是贺新年的鞭炮声。",
		"desc_msg"	:	"春天",
	]),
	([	"month"		: 	1,
		"day"		:	15,
		"event_msg"	:	"元宵节到了，人家门口都挂了红红的灯笼。",
		"desc_msg"	:	"春天",
	]),
	([	"month"		: 	3,
		"day"		:	10,
		"event_msg"	:	"清明节到了，万物复苏的生机流动在淡淡的春烟里。",
		"desc_msg"	:	"春天",
	]),
	([	"month"		: 	4,
		"day"		:	1,
		"event_msg"	:	"炎热的夏天到了，远山都披上了葱郁的绿色。",
		"desc_msg"	:	"夏天",
	]),
	([	"month"		: 	5,
		"day"		:	5,
		"event_msg"	:	"端午节到了，粽叶的香味飘浮在街道上。",
		"desc_msg"	:	"夏天",
	]),
	([	"month"		: 	7,
		"day"		:	1,
		"event_msg"	:	"凉爽的秋天到了，天空似乎更加清朗高远。",
		"desc_msg"	:	"秋天",
	]),
	([	"month"		: 	7,
		"day"		:	7,
		"event_msg"	:	"七夕节到了，今夜的银河是不是会变得很清浅？",
		"desc_msg"	:	"秋天",
	]),
	([	"month"		: 	7,
		"day"		:	15,
		"event_msg"	:	"鬼节到了，空气中弥漫着祭祀火烛的气息。",
		"desc_msg"	:	"秋天",
	]),
	([	"month"		: 	8,
		"day"		:	15,
		"event_msg"	:	"中秋节到了，今夜的月亮最圆的，也是人们最期盼团圆的一天。",
		"desc_msg"	:	"秋天",
	]),
	([	"month"		: 	9,
		"day"		:	9,
		"event_msg"	:	"重阳节到了，金黄与火红的颜色涂画在林间。",
		"desc_msg"	:	"秋天",
	]),
	([	"month"		: 	10,
		"day"		:	1,
		"event_msg"	:	"寒冷的冬天到了，北风中，大雁成阵排空向南飞去。",
		"desc_msg"	:	"冬天",
	]),
	([	"month"		: 	12,
		"day"		:	8,
		"event_msg"	:	"腊八节到了，人们在忙碌着准备过年。",
		"desc_msg"	:	"冬天",
	])
});

mapping *weather_msg = ({
	({	([	"weather"	:	"晴",
			"message"	:	({	"天晴了，天空中万里无云。",
								"鸟语声声，花儿带着蕾，含羞半开，空气中弥漫着青草的甜香。"}),
			"chance"	:	20,
			"length"	:	4,
		]),
		([	"weather"	:	"小雨"	,
			"message"	:	({ 	"依稀的小雨如雾如织，绵绵地笼在周围。",
								"春雨纷纷落下，湿淋淋的柳绦间早来的黄莺飞舞。" }),
			"chance"	:	40,
			"length"	:	4,
		]),
		([	"weather"	:	"微风"	,
			"message"	:	({ "轻柔的微风拂过你的面颊，带来春花芬芳的气息。",
								"柔和的春风吹起，温柔的不需要呵护。" }),
			"chance"	:	20,
			"length"	:	2,
		]),
		([	"weather"	:	"阵风",
			"message"	:	({ "平地起来一阵阵急风，把堆积如雪的杨花柳絮吹的弥漫天空。" }),
			"chance"	:	10,
			"length"	:	1,
		]),
		([	"weather"	:	"狂风",
			"message"	:	({ "天空忽然暗了起来，远处隐隐透出黄色。\n突然间，狂风夹着黄尘铺天盖地而来。" }),
			"chance"	:	10,
			"length"	:	1,
		])
	}),
	({	([	"weather"	:	"晴",
			"message"	:	({ "天晴了，几朵淡淡的云彩妆点著清朗的天空。",
								"红了樱桃，绿了芭蕉，夏就这样突如其来。"}),
			"chance"	:	30,
			"length"	:	4,
		]),
		([	"weather"	:	"急雨"	,
			"message"	:	({ 	"沉雷过后，急雨铺天盖地而来，空气一下清凉了许多。",
								"雷声轰鸣，落花满地，夏天的暴雨终于倾盆而至。", 
								"霹雷一声，倾盆的暴雨就像是一股积郁在胸中已久的怒气，终于落了下来。" }),
			"chance"	:	20,
			"length"	:	2,
		]),
		([	"weather"	:	"雷雨"	,
			"message"	:	({ 	"一道银色的亮光滑过乌云密布的天空，紧接着轰隆隆的雷声丛天际滚过，\n豆大的雨点哗啦啦的落下。",
								"乌云不时的被闪电划开，震耳的雷声就似在你的头顶上炸开。\n转眼间地上就积起一洼洼的雨水。"}),
			"chance"	:	10,
			"length"	:	1,
			"event" 	:	"event_summer_thunder",
		]),
		([	"weather"	:	"微风"	,
			"message"	:	({ "仿佛有人为你轻摇扇子般，清爽的微风让你精神一振，暑闷全消。",
								"热烈而缠绵的夏风如情人的手，令人渴望着，拂过后又令人燥热难安。" }),
			"chance"	:	15,
			"length"	:	2,
		]),
		([	"weather"	:	"阵风",
			"message"	:	({ "几股旋风刮过前方，象一群喧闹追逐的孩子，留下了后面飞起的尘土。" }),
			"chance"	:	20,
			"length"	:	1,
		]),
		([	"weather"	:	"冰雹",
			"message"	:	({ "远处的积云象乌黑的山峰，迅速向这边推进。\n一阵电闪之后，震耳欲聋的霹雳夹着冰雹狂泻而下。" }),
			"chance"	:	5,
			"length"	:	1,
			"event"		:	"event_summer_storm",
		])
	}),
	({	([	"weather"	:	"晴",
			"message"	:	({ 	"天晴了，白云在天空中飘来飘去。",
								"晴空舒朗高净，碧水泛波，远远的，有雁过的声音。" }),
			"chance"	:	30,
			"length"	:	4,
		]),
		([	"weather"	:	"雨"	,
			"message"	:	({ "灰灰的天空，开始淅淅沥沥地下起雨来，\n一滴滴落在地上的声音似乎格外清晰。" }),
			"chance"	:	10,
			"length"	:	2,
		]),
		([	"weather"	:	"微风"	,
			"message"	:	({ "一阵凉风吹过，几片落叶缓缓飘了下来。" }),
			"chance"	:	30,
			"length"	:	2,
		]),
		([	"weather"	:	"阵风",
			"message"	:	({ 	"忽然之间刮起一阵大风，树叶尘土满天飞舞。",
								"秋天的风呼啸而过那无云的碧蓝天空。",
								"风在呼啸，啸声如鬼卒挥鞭，抽冷了归人的心，也抽散了过客的魂魄。" }), 
			"chance"	:	20,
			"length"	:	1,
		]),
		([	"weather"	:	"大雨",
			"message"	:	({ "吹来的风忽然变得有些阴冷，急雨毫无征兆的倾盆而下，\n枯枝败叶被雨点打得痉挛般地跳动。" }),
			"chance"	:	10,
			"length"	:	1,
		])
	}),
	({	([	"weather"	:	"晴",
			"message"	:	({ 	"天晴了，厚厚的云层堆积在天边。",
								"空气清冷，丝丝梅的清香飘过。冬阳撒下，带来点点的暖意。" }),
			"chance"	:	25,
			"length"	:	4,
		]),
		([	"weather"	:	"雪"	,
			"message"	:	({ "一片一片的雪花悠悠荡荡地飞舞落下，地上很快就铺上了银白色。",
								"冬雪纷纷扬扬的落着，静悄悄的，无声无息的覆下来。" }),
			"chance"	:	25,
			"length"	:	1,
		]),
		([	"weather"	:	"微风"	,
			"message"	:	({ "阵阵寒风吹来，你只觉得眼眸都冷得有些酸痛。" }),
			"chance"	:	20,
			"length"	:	1,
			"event"		:	"event_winter_wind",
		]),
		([	"weather"	:	"阵风",
			"message"	:	({ "冷风呼啸着吹过，高处的积雪被吹得纷纷扬扬地落下。" }),
			"chance"	:	10,
			"length"	:	1,
		]),
		([	"weather"	:	"大雪",
			"message"	:	({ "如铅般久积的阴云下，终于飘起了雪花。\n雪花越来越密集，迅速充斥了一切空间，让人几乎睁不开眼睛。",
								"大雪横飞，在风里横越过天空，呼啸着，眨眼间，压的满树满枝。" }),
			"chance"	:	20,
			"length"	:	3,
		])
	}),
});

nosave int current_day_phase;
nosave int current_year_phase;
nosave int current_season;
nosave string current_weather;

void update_day_phase(int curPhase);
void update_year_phase(int curPhase);
void update_weather();
void init_nature_system();
int get_season();
string get_weather();

void create() {
	init_nature_system();
}

mixed *getTime(int date) {
	int curYear, curMonth, curDay, curSheChen, curKe, curDayTime;
	
	curDayTime = date % 1440;
	curKe = (date % 120) / 30;
	curSheChen = (date / 120) % 12;
	curDay = (date / 1440) % 30;
	curMonth = (date / 43200) % 12;
	curYear = (date / 518400);
	
	return ({curKe, curSheChen, curDay, curMonth, curYear, curDayTime});
}

void set_Season(int month) {
	if(month <= 3) {
		current_season = 1;
	} else if(month <= 6) {
		current_season = 2;
	} else if(month <= 9) {
		current_season = 3;
	} else {
		current_season = 4;
	}
}

// initialize nature system.
void init_nature_system() {
	mixed *local;
	int cur_time, month, day, dayTime, i, delay;

	// Get current month, day and time.
	cur_time = time();
	local = getTime(cur_time);
	month = local[3] + 1;
	day = local[2] + 1;
	dayTime = local[5];

	// Find the day phase.
	current_day_phase = -1;
	for(i=0; i < sizeof(day_phase); i++) {
		if(day_phase[i]["start_at"] > dayTime) {
			delay = cur_time - dayTime + (int)day_phase[i]["start_at"];
			EVENT_D->add_event(delay, this_object(), (: update_day_phase, i :)); 
			current_day_phase = i - 1;
			break;
		}
	}
	if(current_day_phase == -1) {
		current_day_phase = sizeof(day_phase) - 1;	
		delay = cur_time - dayTime + 1440;
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, 0 :)); 
	}
	
	// Find the year phase.
	current_year_phase = -1;
	for(i=0; i<sizeof(year_phase); i++) {
		if(month < year_phase[i]["month"] || 
				(month == year_phase[i]["month"] && day < year_phase[i]["day"])) {
			delay = cur_time - dayTime + ((year_phase[i]["month"] - month) * 30 + year_phase[i]["day"] - day) * 1440;
			EVENT_D->add_event(delay, this_object(), (: update_year_phase, i :)); 
			current_year_phase = i - 1;
			break;
		}
	}
	if(current_year_phase == -1) {
		current_year_phase = sizeof(year_phase) - 1;	
		delay = cur_time - dayTime + ((12 - month) * 30 + 30 - day + 1) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase, 0 :)); 		
	}
	set_Season(month);
	update_weather();
}

void update_day_phase(int curPhase) {
	int delay, cur_time;
	
	current_day_phase = curPhase;
	cur_time = time();
	if(curPhase == sizeof(day_phase) - 1) {
		delay = cur_time - (cur_time % 1440) + 1440;
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, 0 :));
	} else {
		delay = cur_time - (cur_time % 1440) + (int)day_phase[current_day_phase + 1]["start_at"];
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, current_day_phase + 1 :));			
	}
	message("outdoor:vision", YEL + REV+ day_phase[current_day_phase]["event_msg"] + "\n\n"NOR, users());
}

void update_year_phase(int curPhase) {
	int delay, cur_time;
	
	current_year_phase = curPhase;
	set_Season(year_phase[current_year_phase]["month"]);
	cur_time = time();
	if(curPhase == sizeof(year_phase) - 1) {
		delay = cur_time - (cur_time % 1440) 
				+ ((12- year_phase[current_year_phase]["month"]) * 30 
				+ 31 - year_phase[current_year_phase]["day"]) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase,  0 :)); 	
	} else {
		delay = cur_time - (cur_time % 1440) 
				+ ((year_phase[current_year_phase+1]["month"] - year_phase[current_year_phase]["month"]) * 30 
				+ year_phase[current_year_phase+1]["day"] - year_phase[current_year_phase]["day"]) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase,  current_year_phase + 1 :)); 
	}
	message("vision", year_phase[current_year_phase]["event_msg"] + "\n\n", users());
}

void update_weather() {
	mixed event = weather_msg[get_season() - 1];
	int i, j, w;
	
	w = random(100);
	for(i=0; i<sizeof(event); i++) {
		if(w < event[i]["chance"]) {
			break; 
		} else {
			w -= event[i]["chance"];
		}
	}
	
	w = random(event[i]["length"] * 1440);
	j = random(sizeof(event[i]["message"]));
	current_weather = event[i]["weather"];
	message("outdoor:vision", REV + event[i]["message"][j] + "\n\n"NOR, users());
	EVENT_D->add_event(time() + w, this_object(), (: update_weather :));
	if(!undefinedp(event[i]["event"])) {
		call_other(this_object(), event[i]["event"]); 
	}
}

void add_day_event(int start_at, int length, object ob, function event_function) {
	int delay, cur_time/*, start_end*/;
	
	if(!objectp(ob)) {
		return;
	}
	start_at = (start_at % 24) * 60;
	cur_time = time();
	if(start_at > (cur_time % 1440)) {
		delay = cur_time - (cur_time % 1440) + start_at + random(length*60);
	} else {
		delay = cur_time - (cur_time % 1440) + 1440 + start_at + random(length*60);
	}
	EVENT_D->add_event(delay, ob, event_function); 
}

void add_year_event(int month, int day, int length, object ob, function event_function) {
	int delay, cur_time, start_at/*, ranDelay*/;
	
	if(!objectp(ob)) {
		return;
	}
	start_at = ((month-1) * 30 + day - 1) * 1440;
	cur_time = time();
	if(start_at > (cur_time % 518400)) {
		delay = cur_time - (cur_time % 518400) + start_at + random(length * 1440); 
	} else {
		delay = cur_time - (cur_time % 518400) + 518400 + start_at + random(length * 1440); 
	}
	EVENT_D->add_event(delay, ob, event_function); 	
	
}

void event_noon() {
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "你觉得一阵晕眩，好像有一股能量从身上被人吸走了。\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "正午时刻，你觉得你的法力开始消失了。\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

void event_summer_thunder() {
	object* list;
	object me;

	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(objectp(me) && objectp(environment(me)) && environment(me)->query("short") == "朝阳峰巅" ) {
		environment(me)->event_thunder(me);
	}

	me = load_object("/d/xiangsi/leidashi");
	if (me)
		me->event_thunder();

}

void event_summer_storm() {
	object* list;
	object me;

	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(environment(me) && environment(me)->query("outdoors") && random(me->query_kar()) < 10) {
		message_vision(HIR"一个大冰雹砸在$N的头上！\n\n"NOR, me);
		me->receive_damage("kee", 50);
	}
}

void event_winter_wind() {
	object* list;
	object me;
	
	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(environment(me) && environment(me)->query("outdoors")) {
		if(random(me->query_con()) > 20) {
			message_vision(HIG"$N深吸一口气，脸色红润了起来。\n\n"NOR, me);
			me->set_temp("apply/durability", 2);
		} else {
			message_vision(HIR"$N不由自主的打了一个寒战！\n\n"NOR, me);
			me->receive_damage("kee", 50);
		}
	}
}

string outdoor_room_description() {
	return "    " + year_phase[current_year_phase]["desc_msg"] + "，" 
			+ get_weather() + "。\n"
			+ "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}

int get_current_day_phase() { 
	return current_day_phase; 
}

int get_current_year_phase() { 
	return current_year_phase;
}

int get_season() { 
	return current_season; 
}

string get_weather() { 
	return current_weather; 
}

int is_day_time() { 
	return ((current_day_phase > 1 && current_day_phase !=7) ? 1 : 0); 
}

string game_time() { 
	return CHINESE_D->chinese_date(time()); 
}

mapping *query_day_phase() { 
	return day_phase; 
}

mixed *get_current_time() { 
	return getTime(time());	
}

mixed get_weather_mesg() {
	return weather_msg[0][1];
}