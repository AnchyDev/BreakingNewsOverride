#ifndef MODULE_BREAKINGNEWS_H
#define MODULE_BREAKINGNEWS_H

#include "ScriptMgr.h"
#include "WardenWin.h"
#include "Player.h"
#include "Config.h"

#include <fstream>
#include <iostream>

bool bn_Enabled;

std::string bn_Title;
std::string bn_Body;
std::string bn_Formatted;

const std::string _prePayload = "wlbuf = '';";
const std::string _postPayload = "loadstring(wlbuf)();wlbuf = nil;";
const std::string _midPayloadFmt = "local saf = ServerAlertFrame;saf:SetParent(CharacterSelect);ServerAlertTitle:SetText('{}');ServerAlertText:SetText('{}');saf:Show();";
uint16 _prePayloadId = 9500;
uint16 _postPayloadId = 9501;
uint16 _tmpPayloadId = 9502;

std::vector<std::string> GetChunks(std::string s, uint8_t chunkSize);
void SendChunkedPayload(Warden* warden, std::string payload, uint32 chunkSize);

class BreakingNewsServerScript : ServerScript
{
public:
    BreakingNewsServerScript() : ServerScript("BreakingNewsServerScript") { }

private:
    bool CanPacketSend(WorldSession* session, WorldPacket& packet) override;
    std::vector<std::string> GetChunks(std::string s, uint8_t chunkSize);
    void SendChunkedPayload(Warden* warden, WardenPayloadMgr* payloadMgr, std::string payload, uint32 chunkSize);
};

class BreakingNewsWorldScript : public WorldScript
{
public:
    BreakingNewsWorldScript() : WorldScript("BreakingNewsWorldScript") { }

private:
    void OnAfterConfigLoad(bool reload) override;
};

#endif //MODULE_BREAKINGNEWS_H
