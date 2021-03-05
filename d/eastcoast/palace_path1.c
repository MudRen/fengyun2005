inherit ROOM;

void create()
{
        set("short", "赤峰路");
        set("long", @LONG
再往东是山区，这儿是岔路口，向南的路宽阔繁华，直通道教圣地[33m武当山[32m。东
方的浓雾之中耸立着一座暗红色的奇峰，直插云霄，云中有几头苍鹰在低低的盘旋
遨翔，仿佛在寻找猎物。东北向的[33m黑松山[32m上云雾缭绕，山脚下有几户人家。（第
一次进相思岭需子时或午时。） 
LONG
        );
        set("exits", ([ 
  	"east" : 	__DIR__"palace_path2",
  	"west" : 	AREA_FYCYCLE"fyeast",
  	"northeast" :   AREA_CHUENYU"dustyroad0",
  	"south" :       AREA_WUDANG"bwuroad1",
]));
        set("outdoors", "palace");

	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_go","go");
}


int do_go(string dir){
	
	object me;
	object /**inv,*/ ob;
	mixed *local;
//	int i,flag=0;
	

	me = this_player();
	local = NATURE_D->getTime(time());

	if (userp(me) && me->query("class") == "moon"	&& dir == "east")
	{
		ob = find_object("/d/xiangsi/qishi");
		if (!ob)
			ob=load_object("/d/xiangsi/qishi");
		message_vision("山上突然飘下一层浓雾，霎时间近在咫尺的景色亦被遮住。\n",me);
		me->move(ob);
		tell_object(me,"你闭上眼睛，按着熟悉的记忆转入，踏进相思岭中。\n");
		message("vision","浓雾转眼间消散无踪，你觉得身边似乎突然少了一个人影．．．\n",this_object()); 
		return 1;
	}

	if( userp(me))
	{
		if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 0)
			me->set_temp("annie/xiangsi_enterance",1);
		else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 6)
		{
			if (local[1] == 0 || local[1] == 6 || me->query_temp("marks/xiangsi/entrance")
				|| REWARD_D->check_m_success(me,"巴山之秘"))
			{
				ob = find_object("/d/xiangsi/qishi");
				if (!ob)
					ob=load_object("/d/xiangsi/qishi");
				message_vision("山上突然飘下一层浓雾，霎时间近在咫尺的景色亦被遮住。\n",me);
				me->move(ob);
				tell_object(me,"你在大雾里向山上行得片刻，忽然惊觉附近的景色竟与记忆中大不相同。\n");
				if (!REWARD_D->check_m_success(me,"巴山之秘")) {
					REWARD_D->riddle_done( me, "巴山之秘",10,1);		
					tell_object(me,"\b（你记住了这里的地形，以后无需再等待子午双时了。）\n");
				}
				me->set_temp("marks/xiangsi/entrance",1);
				me->delete_temp("annie/xiangsi_enterance");
				message("vision","浓雾转眼间消散无踪，你觉得身边似乎突然少了一个人影．．．\n",this_object()); 
				return 1;
			}
			else
				me->delete_temp("annie/xiangsi_enterance");
		}
		else
			me->delete_temp("annie/xiangsi_enterance");
	}
	
	return 0;
}