#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "keen"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1504700177"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "离水小筑");
set("long", @LONG
一进豫园，迎面就看见三穗堂，堂前栽着几颗苏铁树，还有一些有名的树，四周那点点绿叶，在细雨中发清发亮。顺着三穗堂的小路走过仰山堂，跨过石门，果真如匾额上写的渐入佳境：十多米高的大假山峥嵘挺拔，气势雄伟。山下的荷池曲径，小桥流水丁冬，丁冬的水声夹杂在阵阵的欢声笑语之中，交织成一曲动人的春曲
山上峰回路转，逶迤曲折，常春树和迎春花黄绿相映，显得格外动人。站在山顶的望江亭上，俯看豫园，青山绿水，亭台楼阁如画美景，尽收眼底，豫园啊，你的精巧的园林建筑果然吸引人们，而你那常驻的春景，更让人心驰神往!

LONG
);
        set("exits", ([
"out" : "/p/residence/sword1.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("timestamp2",TIMESTAMP2);
	set("free_space",FREE_SPACE);
	set("basic_tax",BASIC_TAX);
	set("basic_score_tax",BASIC_SCORE_TAX);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}
