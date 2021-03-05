inherit ROOM;
#include <ansi.h>

int do_look(string arg);
void create()

{
        set("short", "拉姆拉错湖");
        set("long", @LONG
西藏三大圣湖之一的拉姆拉错，湖面宽阔辽远象一弯新月，一面拥抱草原，一
面依偎雪山。近处湖水闪着幽蓝的光，一浪浪地卷向岸边，淘尽了泥沙。湖边数不
清的玛坭堆，堆着转湖的人们数不清的愿望，湖边的礁石上也刻着“嗡呗呢咪嘛哞”
的六字真言。
LONG
        );
        set("exits", ([ 
		"southwest":  __DIR__"garden",
		]));
        set("objects", ([
        	__DIR__"npc/horse2":	1,
		]) );
		
		set("item_desc",	([
			
		]));	
		
		set("outdoors", "guanwai");
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",10);
		setup();

}

void init(){
		add_action("do_look","look");
}



int 	do_look(string arg){
		object /*room,*/ me = this_player();
		int duration, mark;
							
		if (arg != "lake" && arg != "湖" && arg != "湖中" && arg!= "湖水")	return 0;
			
		if (REWARD_D->riddle_check(me,"灵童转世") == 999)
		{
			duration = me->query("timer/lingtong") + 3600 - time();
			if (duration>0)
			{
				tell_object(me,"你觉得脑海中一阵晕眩，无法静下心来观湖。\n");
				tell_object(me,"（需等待"+ chinese_number(duration/60) + "分钟）\n");
				return 1;
			}
			REWARD_D->riddle_set(me,"灵童转世", 4);
			me->delete("timer/lingtong");
		}
				
		if (REWARD_D->riddle_check(me,"灵童转世") != 4)
		{
			tell_object(me,"拉姆拉错湖水碧蓝，波光粼粼，浅得很，想是山上积雪融化后注入的吧。\n");
			return 1;
		}
		
		if (me->is_busy())
		{
			tell_object(me,"你现在正忙，无法静下心来观湖。\n");
			return 1;
		}
			
		tell_object(me, YEL"你焚香、合掌、闭目、念经，然后向湖中望去。\n"NOR);
		me->start_busy(1);
		
		if (query("kids_out") || random(5))	
		{
			tell_object(me,"湖水荡漾，映着岸边群树的倒影，你的眼睛都酸了，还是没有看出什么。\n");		
			return 1;
		}
		
		tell_object(me,HIG"\n轻烟缭绕，水面慢慢泛起涟漪，渐大渐远，波心中隐隐显出湖光山色。\n"NOR);

tell_object(me,CYN"


        __   ,:`-_    /\   /\            ,d@@b,
     ,-'W;`./WI;:.`-./W;.\/;.\_          @@@@@@
   ,'WWI;::.\ W;:' /WWWI;.`--'.\         `?@@P'
  /WWI;;;:. .`.W' /WWWII;:..:;:.`-.__
<= Mystery is the key to enchantment `=>--------------------------
  \  ~     -  '   \  ~ _      ~  -'      _~-~~   _   ~        ~
   `    ~   /  ~   \       ~-  /   ~     ~-_~-~        -  ~      ~
 ~   `-.   '\     .- \ ~ /\  /~          -~_ ~-
        ~~   `.,-~    \/   \/    -    ~  ~

"NOR);
		
		me->start_busy(30);
		
		mark = random(10);
		call_out("do_riding",2,me, mark,  0);
		
/*		for (i=0;i<sizeof(area);i++) {
			room = load_object("/d/"+area[i]);
			if (!room)	write("error = " + area[i]+"\n");
		}*/
		
			
				
		set("kids_out",1);
		call_out("kid_off",1200, me, 0); 	
		return 1;
	
}

string view(string room) {
	int i;
	object *inv,env;
//	mapping exits;
	string /*roomdesc,*/ str/*, *dirs*/;
	
	env = find_object(room);
	if (!env) env = load_object(room);

	str = CYN"\n\n水波晃动，眨眼间又换了一番景象。\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),
	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}


void do_riding(object me,int mark, int count)
{
	object room, kid;
	int /*i,*/ num;
	string msg;
	string *area = ({ 	"baiyun/skystreet3","biancheng/road2","chenxiang/cxcenter",
						"eren/groad4","fugui/xiaojie3","fy/fysquare",
						"huangshan/wenquan","huashan/hpath2","jinan/street3",
						"laowu/street","loulan/saintpalace","qianfo/road1",
						"qingping/road2","resort/front_yard",	"songshan/shuyuan",
						"taiping/mroad5","taishan/luohan","taoguan/road1",
						"xinjiang/bazha3","biancheng/grassland4", "bat/renjiandao2",
						"changchun/moonding", "chuenyu/sunnyroad","fycycle/road3",
						"wudang/wuroad4", "wanmei/cleft","baiyun/hillroad",
					});
		
		
	if (!me || environment(me)!= this_object())
		return;
		
	if (count < 10 )
	{
		kid = new("/obj/npc/lamakid");
		kid ->set("starter", me);
		num = random(sizeof(area));
		if (!(room = find_object("/d/"+area[num])))
			room = load_object("/d/"+area[num]);			
		
		if (count == mark) {
			kid->set("lama_owner", me);
			set("real_room","/d/"+area[num]);
		}
		
		if (!kid->move(room))
			destruct(kid);
//		write(" number " + count + "\n");
		message_vision(view("/d/"+area[num]),me);
		count ++;
		call_out("do_riding",2,me, mark, count);
	}
	else
	{
		message_vision(HIG"\n\n水波渐平，一切又恢复了原来的肃静。\n\n"NOR, me);
		me->stop_busy();
		msg = "大昭寺于"+ NATURE_D->game_time()+ "开始探访班禅转世灵童。";
		CHANNEL_D->do_sys_channel("info", msg);
		return;
	}
}


int kid_off(object me, int flag) {
    object *ob_list;
    int i;
    string msg;
    set("kids_out",0);
    
    ob_list = children("/obj/npc/lamakid");
	for(i=0; i<sizeof(ob_list); i++) {
    	if(environment(ob_list[i])) {
        	message_vision(CYN"$N双掌合十道：该去了！\n"NOR,ob_list[i]);
        	ob_list[i]->move(VOID_OB);
        }
        destruct(ob_list[i]);    
    }
    if (!flag) {
		msg = "大昭寺探访班禅转世灵童历时数载，未果而终。";
		REWARD_D->riddle_set(me,"灵童转世", 999);	// failed
		me->set("timer/lingtong", time());	
	}
	else
		msg = "大昭寺几经周折，终于" + NATURE_D->game_time()+ "请得班禅转世灵童。";
		
	CHANNEL_D->do_sys_channel("info", msg);    
}

int ending(object me, int flag) {
	
//	string msg;
	remove_call_out("kid_off");
	call_out("kid_off", 2, me, flag);
	return 1;
}