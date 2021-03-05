/************************************************
 * vrm_server.c                                 *
 * 虚拟的随机迷宫创造器 (Virtual Random Maze)   *
 *                                              *
 * by Find.                                     *
 * modified by suu to make it work in fy        *
 * modified by silencer to make it more fun :D	*
 * modified by annie to make it support Z-Line	*
 ************************************************/

/******************************************************
 * 迷宫是一个游戏里经常要用到的东西，以前的迷宫都需要 *
 * 巫师一个房间一个房间地手工绘制，费时费力，而且一旦 *
 * 被玩家找出正确的线路，迷宫格局被泄漏，迷宫就不称其 *
 * 为迷宫了，所以巫师们都绞尽脑汁把迷宫设计的尽量复杂,*
 * 但再复杂的迷宫早晚也会被找到正确的路线，而且过于复 *
 * 杂难走的迷宫也使玩家感觉过于繁琐，降低乐趣。因此产 *
 * 生此想法。                                         *
 * 随机迷宫的产生算法尽量简单，迷宫的储存尽量节省记忆 *
 * 体，迷宫房间采用虚拟物件，处理灵活，迷宫房间只有在 *
 * 玩家走到时才会装进内存，而且迷宫房间也象普通的ROOM *
 * 一样当一段时间没有被参考到可以销毁节省记忆体，当整 *
 * 个迷宫一段时间没有被参考到可以被完全摧毁，下次再需 *
 * 要的时候会重新建立，又会产生一个新的迷宫。区域巫师 *
 * 写作随机迷宫只需规定一些预设的参数如迷宫的单边长、 *
 * 房间描述、出入口描述，几十个乃至几千个房间、路线时 *
 * 时不同的随机迷宫就建立好了，大大提高了区域写作效率 *
 * 和游戏的可玩性。                                   *
 * 此物件目前适合于随机的迷宫，即：迷宫内房间的描述基 *
 * 本相同，比如一片树林、一片坟地等，如要此物件创作完 *
 * 整的随机区域即有一定的情节、一定格局的区域，则需要 *
 * 根据自己的情况规定出迷宫内房间描述的一些规则，使相 *
 * 邻房间的描述变化合理，房间内物件与描述协调。如果愿 *
 * 意巫师可以只制作迷宫间的连接部分，而用几个迷宫组合 *
 * 成一个完全随机的区域，哈，那以后做巫师可轻松多了。 *
 * 目前本游戏使用的迷宫一般为单边长10至40，到底能做多 *
 * 大的迷宫我也不知道，下面对此有一个说明，要根据自己 *
 * 的服务器性能来讲，不过我想最普通的机器制作一个面积 *
 * 为100x100的迷宫应该也是一件轻松的事情。            *
 * 由于采用 virtual object，牵涉到一点安全问题，需要根*
 * 据自己的系统考量调整。                             *
 ******************************************************/

#pragma optimize

#define UP		32	// damn,ansi.h already defined U
#define D		16
#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		63

/****************************************************
 * 迷宫的单边长最大值目前暂定为 100，由于随机迷宫的
 * 创造和操作比较耗费资源单边长 100 的迷宫'面积'就是
 * 100x100 等于 10000 个房间的一个迷宫，一般恐怕是用
 * 不到。一般的实时迷宫（实时迷宫是指在游戏运行过程
 * 中随时被 destruct 随着需要又会随时被创建的迷宫）的
 * 单边长以 10 到 50 之间为宜。如需创造巨型迷宫如有几
 * 万乃至十几万个房间的迷宫，应将创建工作放置于游戏启
 * 动时做，游戏启动的一段时间（比如20秒）禁止玩家登入。
 * 游戏通过定期重新启动来更新此迷宫。
 * 不知谁会用到这么大的迷宫。。。。。。
 ****************************************************/
#define MAX_LONG	100

// 只要能与其他房间相连的房间就肯定有一个入口.
// 而可能的出口有五个.
// define 这项规定房间最多只能有两个出口.
// 也就是对于有五个出口的房间会随机关闭三个.
// 不会使玩家由于看到六个方向都有出口很烦
// 降低游戏乐趣。
#define VALID_LEAVES 3

inherit F_CLEAN_UP;
#include <ansi.h>;

class coordinate{ int x; int y; int z;}
class coordinate *newpath = ({}),/*待处理队列*/
	enter,/* 入口坐标 */
	leave;/* 出口坐标 */

private string *valid_dirs = ({ "south","north","west","east","up","down",});
private mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
"down"	: "up",
"up"	: "down",
]);


// 全迷宫出口阵列.
private mixed *all;

/***************** 迷宫的一些预设特性：*****************/
private int l;				// 迷宫的东西向单边长
private int m;				// 迷宫的南北向单边长
private int h;				// 迷宫的高低向单边长
private int s;				// 迷宫每格的坐标差，ｄｅｆａｕｌｔ＝１０
private string *inherit_rooms = ({});	// 迷宫允许继承的档案名称
private string entry_dir;		// 迷宫入口方向
private string link_entry_dir;		// 迷宫入口与区域的连接方向
private string link_entry_room;		// 迷宫入口所连接区域档案的文件名
private int link_entry_room_x;		// 迷宫入口的x坐标
private int link_entry_room_y;		// 迷宫入口的y坐标
private int link_entry_room_z;		// 迷宫入口的z坐标
private string link_exit_dir;		// 迷宫出口与区域的连接方向
private string link_exit_room;		// 迷宫出口所连接区域档案的文件名
private string entry_short;		// 迷宫入口的短描述
private string entry_desc;		// 迷宫入口的长描述
private string exit_short;		// 迷宫出口的短描述
private string exit_desc;		// 迷宫出口的长描述
private string *maze_room_desc	= ({});	// 迷宫房间的长描述
private string maze_room_short;		// 迷宫房间的短描述
private int is_outdoors = 0;		// 迷宫房间是否为户外
private int refresh_delay = 0;  	//迷宫重建时间, default is 0 means no recreation
private int private_flag;				// Privite Maze? // annie. 09.2003
/******************* ---- END ---- *********************/

// 建立标记.
private int maze_built = 0;

// 重置全域变量.
private void refresh_vars();

// 建立迷宫
private void create_maze();

// 选择随机出口.
private int random_out(int x,int y,int z,int n);

//设置迷宫单位长
private void set_maze_spacing(int space);

// 处理连接.
private void link_to_north(int x,int y,int z);
private void link_to_south(int x,int y,int z);
private void link_to_west(int x,int y,int z);
private void link_to_east(int x,int y,int z);
private void link_to_up(int x,int y,int z);
private void link_to_down(int x,int y,int z);

// 绘制已建成迷宫的地图.
private void paint_vrm_map();

// 检查某个房间里是否有 players
private int player_in(object m_room);

// 去除迷宫 --- 所有players将去VOID
private void remove();

// 重新创建迷宫
private void refresh_maze();

// 调试信息。
private string mroom_fname(int x,int y,int z)
	{ return sprintf("%s/%d/%d/%d",base_name(this_object()),x,y,z);}
	
int query_maze_length(){
	return l;
}	

int query_maze_height(){
	return m;
}

int query_maze_altitude(){
	return h;
}

// 重置全域变量.
private void refresh_vars() 
{
	newpath = ({});
	all = 0;
}

// 对一些必设参数的合法性检查
private int check_vars()
{
	int i,n;

	if( (l < 2) || l > MAX_LONG )
		return 0;

	if( (m < 2) || m > MAX_LONG )
		return 0;
		
	if( h > MAX_LONG )
		return 0;
		
	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}


private int random_out(int x,int y,int z,int n) // 选择随机出口函数.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;
		temp->z = z;

		// 西面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;
		temp->z = z;

		// 东面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;
		temp->z = z;

		// 南面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < m)
	&& !all[x][y+1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;
		temp->z = z;

		// 北面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

	// The up room is (x,y,z+1)
	if( n&UP
	&& ((z+1) < h)
	&& !all[x][y][z+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z+1;

		// 上面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ UP });
	}

	// The down room is (x,y,z-1)
	if( n&D
	&& ((z-1) >= 0)
	&& !all[x][y][z-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z-1;

		// 下面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ D });
	}

#ifdef VALID_LEAVES
	// 如果有三个出口,随机关闭一个.	// ann' marked
//	if(sizeof(outs) >= 3)
	while(sizeof(outs) >= VALID_LEAVES)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

private void create_maze()
{
	int i,j;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // 重置全域变量.
	if( !check_vars() )   // 对一些预设变量进行检查。
		return;

	// 1.确定迷宫单边长.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(m);	// 建立数组.
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			all[i][j] = allocate(h);	// 建立数组.
	
	CHANNEL_D->do_sys_channel("sys",sprintf("Start buliding maze"));
	CHANNEL_D->do_sys_channel("sys",sprintf("Start buliding maze in %s",base_name(this_object())));
	
	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter 入口坐标.
			enter->x = to_int(l/2); // 取中迷宫比较平衡。
			enter->y = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = m-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= N;
			break;
		case "west":
			enter->y = to_int(m/2);
			enter->x = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= W;
			break;
		case "east":
			enter->y = to_int(m/2);
			enter->x = l-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= E;
			break;
		case "up":
			enter->z = h-1;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= UP;
			break;
		case "down":
			enter->z = 0;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= D;
			break;
	}

	// 存入待处理队列.
	newpath += ({ enter });

	// 进入主循环.
	do
	{
		int x,y,z,out,numb;

		// 进行一些监测与初始化.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;
		z = newpath[numb]->z;

		// 如果有三个可能的出口随机关闭一个出口:
		out = ALL^(all[x][y][z]);
		out = random_out(x,y,z,out);

		if(!out) // 没有可能的出口了.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// 处理连接.
		if(out&W) link_to_west(x,y,z);
		if(out&E) link_to_east(x,y,z);
		if(out&N) link_to_north(x,y,z);
		if(out&S) link_to_south(x,y,z);
		if(out&UP) link_to_up(x,y,z);
		if(out&D) link_to_down(x,y,z);

		// 当前房间处理完毕.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[l-1][i][j])
					{
						temp = new(class coordinate);
						temp->x = l-1;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "east":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[0][i][j])
					{
						temp = new(class coordinate);
						temp->x = 0;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "south":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][m-1][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = m-1;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "north":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][0][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = 0;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "up":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][0])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = 0;
						valid_leaves += ({temp});
					}
			break;
		case "down":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][h-1])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = h-1;
						valid_leaves += ({temp});
					}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // 没有出口 须重新建立
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // 随机选一个.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y][leave->z] |= N;
			break;
		case "north":
			all[leave->x][leave->y][leave->z] |= S;
			break;
		case "west":
			all[leave->x][leave->y][leave->z] |= E;
			break;
		case "east":
			all[leave->x][leave->y][leave->z] |= W;
			break;
		case "up":
			all[leave->x][leave->y][leave->z] |= D;
			break;
		case "down":
			all[leave->x][leave->y][leave->z] |= UP;
			break;
	}

	// 迷宫创建完毕。
	maze_built = 1;
	
	if (refresh_delay > 0  )
	{
		EVENT_D->add_event(time()+refresh_delay,this_object(),(:refresh_maze:));
	}
	
	// 绘制完成的迷宫地图。
	// 地图文件为同目录下同名的'.map' 文件，
	// 绘制地图也许可利于区域巫师的工作。
	// 如需要可开放物件对于本目录的'写'。
		    paint_vrm_map();	// ann' marked
}




private void link_to_west(int x,int y,int z)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. 当前房间已经是最西面的房间了.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;
	temp->z = z;

	// 西面的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= W;
	all[temp->x][temp->y][temp->z] |= E;
	newpath += ({temp});
}

private void link_to_east(int x,int y,int z)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. 当前房间已经是最东面的房间了.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;
	temp->z = z;

	// 东面的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= E;
	all[temp->x][temp->y][temp->z] |= W;
	newpath += ({temp});
}

private void link_to_south(int x,int y,int z)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最南端的房间了.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;
	temp->z = z;

	// 南端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= S;
	all[temp->x][temp->y][temp->z] |= N;
	newpath += ({temp});
}

private void link_to_north(int x,int y,int z)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最北端的房间了.
	if( (y+1) >= m )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;
	temp->z = z;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= N;
	all[temp->x][temp->y][temp->z] |= S;
	newpath += ({temp});
}

private void link_to_up(int x,int y,int z)	// The up room is (x,y,z+1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最上层的房间了.
	if( (z+1) >= h )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z+1;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= UP;
	all[temp->x][temp->y][temp->z] |= D;
	newpath += ({temp});
}

private void link_to_down(int x,int y,int z)	// The up room is (x,y,z-1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最下层的房间了.
	if( (z-1) < 0)
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z-1;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= D;
	all[temp->x][temp->y][temp->z] |= UP;
	newpath += ({temp});
}

// 绘制已建成迷宫的地图.
// ann' marked 暂时不叫此函式。
private void paint_vrm_map()
{
	string hor = "─" ,ver = "│  ",room = "◎",sroom = "●",ld = "▽", lu = "△", lb = "◇";
	int x,y,z;
	string output = "",map_file;

	for (z = (h-1); z>=0; z--)
	{
		for(y=(m-1);y>=0;y--)
		{
			reset_eval_cost();

			output += sprintf("y=%-3d: ",y);
			for(x=0;x<l;x++)
			{
				if ( (x==enter->x && y==enter->y && z == enter->z)
					|| (x==leave->x && y==leave->y && z == leave->z) )
				{
					output += sroom;
				}
				else if ((all[x][y][z])&UP && (all[x][y][z])&D)
				{
					output += lb;
				}
				else if ((all[x][y][z])&UP)
				{
					output += lu;
				}
				else if ((all[x][y][z])&D)
				{
					output += ld;
				}
				else
				{
					output += room;
				}

				if( (all[x][y][z])&E ) // have east
					output += hor;
				else
					output += "  ";
			}

			output += "\n";
			output += "       ";
			for(x=0;x<l;x++)
			{
				if( (all[x][y][z])&S ) // have south
					output += ver;
				else
				output += "    ";
			}
			output += "\n";
		}
		output += "\nFloor "+z+"\n ------------------------------\n";
	}

	map_file = sprintf( "%s.map",base_name(this_object()) );
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y,z;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					maze_objs += ({find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// 巫师可以 update 区域迷宫主物件强制更新迷宫，
// 但此时迷宫中的玩家就要去 VOID 了。

void remove()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;
	
	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					destruct(m_room);
	if(objectp(m_room = find_object(sprintf("%s/entry",fname))))
		destruct(m_room);
	if(objectp(m_room= find_object(sprintf("%s/exit",fname))))
		destruct(m_room);
}

void refresh_maze()
{
	if (this_object()->has_player())
	{
		//has players in maze re-try 10 mins later;
		CHANNEL_D->do_sys_channel("sys","maze has players in, will retry 10 mins later");
		EVENT_D->add_event(time()+600,this_object(),(: refresh_maze :));
		return;
	}
	remove();
	CHANNEL_D->do_sys_channel("sys","maze destructed");
	destruct(this_object());
	return;
}

//	检查迷宫中是否有玩家
int has_player()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;

	for(x=0;x<l;x++)
	{
		for(y=0;y<m;y++)
		{
			for(z=0;z<h;z++)
			{
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					if (player_in(m_room))
						return 1;
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/entry",fname))))
		if (player_in(m_room))
			return 1;

	if(objectp(m_room = find_object(sprintf("%s/exit",fname))))
		if (player_in(m_room))
			return 1;
	return 0;
}

//	检查某个房间里是否有玩家。

int player_in(object m_room)
{
	object *inv;
	inv = all_inventory(m_room);
	for (int i = 0;i < sizeof(inv) ; i++)
		//if player in the room return
		if (userp(inv[i]))
			return 1;

	return 0;
}


//	把所有玩家从迷宫里搬走。
int remove_all_players(object maze_room,object exile_room,string remove_msg){
	
	string fname = base_name(maze_room);
	object m_room,*inv;
	int x,y,z,k,num,length,height,altitude;

	length=maze_room->query_maze_length();
	height=maze_room->query_maze_height();
	altitude=maze_room->query_maze_altitude();
	
	
	for(x=0;x<length;x++)
	{
		for(y=0;y<height;y++)
		{
			for(z=0;z<altitude;z++)
			{
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z)))) {
					tell_room(m_room,remove_msg);
					inv=all_inventory(m_room);
					num=sizeof(inv);
					while(num--) {
						if (userp(inv[num])) 
							inv[num]->move(exile_room);	
						if (inv[num]->query("possessed"))
						if (userp(inv[num]->query("possessed")))
							inv[num]->move(exile_room);	
					}	
				}	
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/entry",fname)))) {
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
			if (userp(inv[num]))
				inv[num]->move(exile_room);	
			if (inv[num]->query("possessed"))
			if (userp(inv[num]->query("possessed")))
				inv[num]->move(exile_room);	
		}
	}
	
	if(objectp(m_room = find_object(sprintf("%s/exit",fname))))	{
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
			if (userp(inv[num]))
				inv[num]->move(exile_room);
			if (inv[num]->query("possessed"))
			if (userp(inv[num]->query("possessed")))
				inv[num]->move(exile_room);		
		}
	}
	
}



/**** 以下是预设迷宫参数的接口函数 ****/
// 迷宫的单边长
void set_maze_long(int mlong, int mheight,int maltitude)
{
	if(!intp(mlong) || !intp(mheight))
		return;

	if (!intp(maltitude))
		maltitude = 0;

	// 最小为 5，再小了没什么意义。
	if( (mlong < 2) || mlong > MAX_LONG 
		|| mheight<2 || mheight > MAX_LONG || maltitude > MAX_LONG)
		return;

	l = mlong;
	m = mheight;
	h = maltitude;
}

// 迷宫房间所继承的物件的档案名称。
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// 此档案是否存在
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// 入口方向(出口在对面)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;
	
	if (dir == "maze_enter")
	{
		dir="north";
		private_flag=1;
	}
	else
		private_flag=0;	

	// 入口方向的合法性检查.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//入口与区域的连接方向
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// 迷宫入口所连接区域档案的文件名
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

// 迷宫入口房间的坐标，我们无法用简单的方法把迷宫坐标安排在
// 进口/出口内（这个需要得到迷宫与区域的关系）
// 所以我们认为迷宫是进口区域延伸的一部分，当走出迷宫出口时，跳跃进入下一个区域。
// 缺点是，一个大迷宫的坐标可能与真实区域重叠，这个就要设计者自己留意了，
// 比如说，不要把100x100的迷宫安排在 (1,1)和 (10,10)之间。。。。自己算一下吧

void set_link_entry_room_x(int x)
{
	if(!intp(x)) link_entry_room_x=0;
		else	link_entry_room_x = x;
}


void set_link_entry_room_y(int y)
{
	if(!intp(y)) link_entry_room_y=0;
		else	link_entry_room_y = y;
}


void set_link_entry_room_z(int z)
{
	if(!intp(z)) link_entry_room_z=0;
		else	link_entry_room_z = z;
}


//设置迷宫单位长
void set_maze_spacing(int space) {
	if (!intp(space)) s=10;
		else s=space;
}


//出口与区域的连接方向
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// 迷宫出口所连接区域档案的文件名
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// 迷宫入口的短描述
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// 迷宫入口的长描述
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// 迷宫出口的短描述
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// 迷宫出口的长描述
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//迷宫房间的短描述
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//迷宫房间的描述，如果有多条描述，制造每个房
//间的时候会从中随机选择一个。
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

//迷宫房间是否为户外房间
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

//迷宫刷新
void set_maze_refresh(int m_refresh)
{
	if (intp(m_refresh) && m_refresh>=1)
		refresh_delay = m_refresh; 
}

/*	*** 以上是预设迷宫参数的接口函数 ***

		
		
		***************** 以下是创建迷宫的主函数 ************************


//	迷宫中的怪物和物件--	从原来的vrm_server中去除了这部分内容，
	一个好的迷宫，不可能用一个数组来写出NPC的分布，必须用一些较复杂的定义和
	判断来使其个性化，所以这里使用的方法是在调用时让inherit_room去继承一个和
	迷宫内容有关的maze-room，在这个文件里可以定义NPC/obj，定义valid_leave,
	add_action等等。
	也就是说，迷宫的文件包括
	1。迷宫创建文件 -- 定义迷宫大小，方位，基本描述，迷宫房间文件
	2。迷宫房间定义文件--迷宫房间的具体定义
	3。本文件
	
// 	创造迷宫房间，由 VIRTUAL_D 调用。*/

nomask object query_maze_room(string str)
{
	int idx,idx2,x,y,z,exits;
	object ob;
	string f;
	
    	seteuid(ROOT_UID);
	seteuid(geteuid());
	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")		return 0;

	if(!maze_built)	// 迷宫未建立
		create_maze();
	if(!maze_built)		return 0;


	if(str == "entry")	// 迷宫入口房间
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];
                                               
		//ob = new(f);
		ob = load_object(f);
		if(!ob)	return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		if (is_outdoors)	ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y,enter->z));
		ob->set("coor/x",link_entry_room_x);
		ob->set("coor/y",link_entry_room_y);
		ob->set("coor/z",link_entry_room_z);
		ob->set("no_fly",1);
		ob->set("entry_room",1);
		ob->set("perma_exist",1);
		ob->setup_entry_room();
		return ob;
	}

	if(str == "exit")	// 迷宫出口房间
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		//ob = new(f);
		ob = load_object(f);
		if(!ob)	return 0;
		ob->set("no_fly",1);
		ob->set("perma_exist",1);
		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		if(is_outdoors)		ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir), mroom_fname(leave->x,leave->y,leave->z));
		switch (entry_dir) {
			case "east":	ob->set("coor/x",link_entry_room_x - l*s - 2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "west":	ob->set("coor/x",link_entry_room_x + l*s +2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "south":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + m*s +2*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "north":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y - m*s -2*s);
					ob->set("coor/z",link_entry_room_z);
					break;		
			case "up":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z - h*s -2*s);
					break;		
			case "down":ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z + h*s +2*s);
					break;		
		}
		ob->set("exit_room",1);
		ob->setup_exit_room();
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))		return 0;

	idx2 = member_array('/', str[idx+1..]);
	if( idx2 == -1 )
		return 0;

	if(!sscanf(str[idx+1..idx+idx2],"%d",y))		return 0;
	if(!sscanf(str[idx+idx2+2..],"%d",z))		return 0;

	if( !exits = all[x][y][z] )		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];

	ob = load_object(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("perma_exist",1);
	ob->set("no_fly",1);
	
//	根据入口坐标和迷宫大小来定义房间坐标
	switch (entry_dir) {
		case "east":	ob->set("coor/x",x*s-l*s+link_entry_room_x-s);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "west":	ob->set("coor/x",x*s+link_entry_room_x+s);
				ob->set("coor/y",y*s-to_int(m/2)*s+link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "south":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s+link_entry_room_y +s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "north":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-m*s+link_entry_room_y-s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "up":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s-h*s+link_entry_room_z-s);
				break;
		case "down":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s+link_entry_room_z+s);
				break;
	}		
				

//	setting exits directions:
	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y,z));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y,z));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1,z));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1,z));
	if(exits&UP)
		ob->set("exits/up",mroom_fname(x,y,z+1));
	if(exits&D)
		ob->set("exits/down",mroom_fname(x,y,z-1));

	if( (x == enter->x) && (y == enter->y) && (z == enter->z))
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));
	if( (x == leave->x) && (y == leave->y)  && (z == leave->z))
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	
	if(is_outdoors)		ob->set("outdoors",1);

//	指向迷宫房间定义文件来设定房间描述
	
	f->setup_room_desc(ob,l,m,x,y,z);	
	
//	指向迷宫房间定义文件来设定怪物/物品	
	f->setup_npc_obj(ob,l,m,x,y,z);
	
//	指向迷宫房间定义文件来设定物品描述
	
	return ob;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
