#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <regex>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include <atomic>
#include <future>
#include <optional>
#include <variant>
#include <set>
#include <deque>
#include <exception>
#include <typeinfo>
#include <ctime>
#include <iomanip>
#include <limits>
#include <numeric>

namespace Discord {

using Snowflake = std::string;
using Timestamp = std::chrono::system_clock::time_point;

enum class ChannelType {
    GUILD_TEXT = 0,
    DM = 1,
    GUILD_VOICE = 2,
    GROUP_DM = 3,
    GUILD_CATEGORY = 4,
    GUILD_NEWS = 5,
    GUILD_STORE = 6,
    GUILD_NEWS_THREAD = 10,
    GUILD_PUBLIC_THREAD = 11,
    GUILD_PRIVATE_THREAD = 12,
    GUILD_STAGE_VOICE = 13,
    GUILD_FORUM = 15
};

enum class MessageType {
    DEFAULT = 0,
    RECIPIENT_ADD = 1,
    RECIPIENT_REMOVE = 2,
    CALL = 3,
    CHANNEL_NAME_CHANGE = 4,
    CHANNEL_ICON_CHANGE = 5,
    CHANNEL_PINNED_MESSAGE = 6,
    GUILD_MEMBER_JOIN = 7,
    USER_PREMIUM_GUILD_SUBSCRIPTION = 8,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11,
    CHANNEL_FOLLOW_ADD = 12,
    GUILD_DISCOVERY_DISQUALIFIED = 14,
    GUILD_DISCOVERY_REQUALIFIED = 15,
    GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = 16,
    GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = 17,
    THREAD_CREATED = 18,
    REPLY = 19,
    CHAT_INPUT_COMMAND = 20,
    THREAD_STARTER_MESSAGE = 21,
    GUILD_INVITE_REMINDER = 22,
    CONTEXT_MENU_COMMAND = 23
};

enum class InteractionType {
    PING = 1,
    APPLICATION_COMMAND = 2,
    MESSAGE_COMPONENT = 3,
    APPLICATION_COMMAND_AUTOCOMPLETE = 4,
    MODAL_SUBMIT = 5
};

enum class ComponentType {
    ACTION_ROW = 1,
    BUTTON = 2,
    SELECT_MENU = 3,
    TEXT_INPUT = 4
};

enum class ButtonStyle {
    PRIMARY = 1,
    SECONDARY = 2,
    SUCCESS = 3,
    DANGER = 4,
    LINK = 5
};

enum class PermissionFlag : uint64_t {
    CREATE_INSTANT_INVITE = 1ULL << 0,
    KICK_MEMBERS = 1ULL << 1,
    BAN_MEMBERS = 1ULL << 2,
    ADMINISTRATOR = 1ULL << 3,
    MANAGE_CHANNELS = 1ULL << 4,
    MANAGE_GUILD = 1ULL << 5,
    ADD_REACTIONS = 1ULL << 6,
    VIEW_AUDIT_LOG = 1ULL << 7,
    PRIORITY_SPEAKER = 1ULL << 8,
    STREAM = 1ULL << 9,
    VIEW_CHANNEL = 1ULL << 10,
    SEND_MESSAGES = 1ULL << 11,
    SEND_TTS_MESSAGES = 1ULL << 12,
    MANAGE_MESSAGES = 1ULL << 13,
    EMBED_LINKS = 1ULL << 14,
    ATTACH_FILES = 1ULL << 15,
    READ_MESSAGE_HISTORY = 1ULL << 16,
    MENTION_EVERYONE = 1ULL << 17,
    USE_EXTERNAL_EMOJIS = 1ULL << 18,
    VIEW_GUILD_INSIGHTS = 1ULL << 19,
    CONNECT = 1ULL << 20,
    SPEAK = 1ULL << 21,
    MUTE_MEMBERS = 1ULL << 22,
    DEAFEN_MEMBERS = 1ULL << 23,
    MOVE_MEMBERS = 1ULL << 24,
    USE_VAD = 1ULL << 25,
    CHANGE_NICKNAME = 1ULL << 26,
    MANAGE_NICKNAMES = 1ULL << 27,
    MANAGE_ROLES = 1ULL << 28,
    MANAGE_WEBHOOKS = 1ULL << 29,
    MANAGE_EMOJIS_AND_STICKERS = 1ULL << 30,
    USE_APPLICATION_COMMANDS = 1ULL << 31,
    REQUEST_TO_SPEAK = 1ULL << 32,
    MANAGE_EVENTS = 1ULL << 33,
    MANAGE_THREADS = 1ULL << 34,
    CREATE_PUBLIC_THREADS = 1ULL << 35,
    CREATE_PRIVATE_THREADS = 1ULL << 36,
    USE_EXTERNAL_STICKERS = 1ULL << 37,
    SEND_MESSAGES_IN_THREADS = 1ULL << 38,
    USE_EMBEDDED_ACTIVITIES = 1ULL << 39,
    MODERATE_MEMBERS = 1ULL << 40
};

struct Color {
    uint32_t value;
    
    Color(uint32_t val = 0) : value(val) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : value((r << 16) | (g << 8) | b) {}
    
    static const Color DEFAULT;
    static const Color AQUA;
    static const Color DARK_AQUA;
    static const Color GREEN;
    static const Color DARK_GREEN;
    static const Color BLUE;
    static const Color DARK_BLUE;
    static const Color PURPLE;
    static const Color DARK_PURPLE;
    static const Color LUMINOUS_VIVID_PINK;
    static const Color DARK_VIVID_PINK;
    static const Color GOLD;
    static const Color DARK_GOLD;
    static const Color ORANGE;
    static const Color DARK_ORANGE;
    static const Color RED;
    static const Color DARK_RED;
    static const Color GREY;
    static const Color DARK_GREY;
    static const Color DARKER_GREY;
    static const Color LIGHT_GREY;
    static const Color NAVY;
    static const Color DARK_NAVY;
    static const Color YELLOW;
};

const Color Color::DEFAULT = Color(0);
const Color Color::AQUA = Color(0x1ABC9C);
const Color Color::DARK_AQUA = Color(0x11806A);
const Color Color::GREEN = Color(0x57F287);
const Color Color::DARK_GREEN = Color(0x1F8B4C);
const Color Color::BLUE = Color(0x3498DB);
const Color Color::DARK_BLUE = Color(0x206694);
const Color Color::PURPLE = Color(0x9B59B6);
const Color Color::DARK_PURPLE = Color(0x71368A);
const Color Color::LUMINOUS_VIVID_PINK = Color(0xE91E63);
const Color Color::DARK_VIVID_PINK = Color(0xAD1457);
const Color Color::GOLD = Color(0xF1C40F);
const Color Color::DARK_GOLD = Color(0xC27C0E);
const Color Color::ORANGE = Color(0xE67E22);
const Color Color::DARK_ORANGE = Color(0xA84300);
const Color Color::RED = Color(0xED4245);
const Color Color::DARK_RED = Color(0x992D22);
const Color Color::GREY = Color(0x95A5A6);
const Color Color::DARK_GREY = Color(0x607D8B);
const Color Color::DARKER_GREY = Color(0x546E7A);
const Color Color::LIGHT_GREY = Color(0xBCC0C0);
const Color Color::NAVY = Color(0x34495E);
const Color Color::DARK_NAVY = Color(0x2C3E50);
const Color Color::YELLOW = Color(0xFEE75C);

template<typename T>
class Collection {
private:
    std::unordered_map<Snowflake, T> data;
    
public:
    using iterator = typename std::unordered_map<Snowflake, T>::iterator;
    using const_iterator = typename std::unordered_map<Snowflake, T>::const_iterator;
    
    Collection() = default;
    Collection(std::initializer_list<std::pair<Snowflake, T>> init) : data(init) {}
    
    T& operator[](const Snowflake& key) { return data[key]; }
    const T& operator[](const Snowflake& key) const { return data.at(key); }
    
    bool has(const Snowflake& key) const { return data.find(key) != data.end(); }
    
    T* get(const Snowflake& key) {
        auto it = data.find(key);
        return it != data.end() ? &it->second : nullptr;
    }
    
    const T* get(const Snowflake& key) const {
        auto it = data.find(key);
        return it != data.end() ? &it->second : nullptr;
    }
    
    void set(const Snowflake& key, const T& value) { data[key] = value; }
    void set(const Snowflake& key, T&& value) { data[key] = std::move(value); }
    
    bool erase(const Snowflake& key) { return data.erase(key) > 0; }
    void clear() { data.clear(); }
    
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    
    iterator begin() { return data.begin(); }
    iterator end() { return data.end(); }
    const_iterator begin() const { return data.begin(); }
    const_iterator end() const { return data.end(); }
    const_iterator cbegin() const { return data.cbegin(); }
    const_iterator cend() const { return data.cend(); }
    
    std::vector<T> array() const {
        std::vector<T> result;
        result.reserve(data.size());
        for (const auto& pair : data) {
            result.push_back(pair.second);
        }
        return result;
    }
    
    std::vector<Snowflake> keyArray() const {
        std::vector<Snowflake> result;
        result.reserve(data.size());
        for (const auto& pair : data) {
            result.push_back(pair.first);
        }
        return result;
    }
    
    T first() const {
        if (data.empty()) throw std::runtime_error("Collection is empty");
        return data.begin()->second;
    }
    
    T last() const {
        if (data.empty()) throw std::runtime_error("Collection is empty");
        return data.rbegin()->second;
    }
    
    T random() const {
        if (data.empty()) throw std::runtime_error("Collection is empty");
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, data.size() - 1);
        auto it = data.begin();
        std::advance(it, dis(gen));
        return it->second;
    }
    
    template<typename Predicate>
    Collection<T> filter(Predicate pred) const {
        Collection<T> result;
        for (const auto& pair : data) {
            if (pred(pair.second, pair.first)) {
                result.set(pair.first, pair.second);
            }
        }
        return result;
    }
    
    template<typename Predicate>
    T* find(Predicate pred) {
        for (auto& pair : data) {
            if (pred(pair.second, pair.first)) {
                return &pair.second;
            }
        }
        return nullptr;
    }
    
    template<typename Predicate>
    const T* find(Predicate pred) const {
        for (const auto& pair : data) {
            if (pred(pair.second, pair.first)) {
                return &pair.second;
            }
        }
        return nullptr;
    }
    
    template<typename Func>
    auto map(Func func) const -> Collection<decltype(func(std::declval<T>(), std::declval<Snowflake>()))> {
        using ReturnType = decltype(func(std::declval<T>(), std::declval<Snowflake>()));
        Collection<ReturnType> result;
        for (const auto& pair : data) {
            result.set(pair.first, func(pair.second, pair.first));
        }
        return result;
    }
    
    template<typename Func>
    void forEach(Func func) const {
        for (const auto& pair : data) {
            func(pair.second, pair.first);
        }
    }
    
    template<typename Predicate>
    bool some(Predicate pred) const {
        for (const auto& pair : data) {
            if (pred(pair.second, pair.first)) {
                return true;
            }
        }
        return false;
    }
    
    template<typename Predicate>
    bool every(Predicate pred) const {
        for (const auto& pair : data) {
            if (!pred(pair.second, pair.first)) {
                return false;
            }
        }
        return true;
    }
    
    template<typename T2, typename Func>
    T2 reduce(Func func, T2 initialValue) const {
        T2 accumulator = initialValue;
        for (const auto& pair : data) {
            accumulator = func(accumulator, pair.second, pair.first);
        }
        return accumulator;
    }
    
    Collection<T> clone() const {
        return Collection<T>(data.begin(), data.end());
    }
    
    void concat(const Collection<T>& other) {
        for (const auto& pair : other.data) {
            data[pair.first] = pair.second;
        }
    }
    
    Collection<T> difference(const Collection<T>& other) const {
        Collection<T> result;
        for (const auto& pair : data) {
            if (!other.has(pair.first)) {
                result.set(pair.first, pair.second);
            }
        }
        return result;
    }
    
    Collection<T> intersect(const Collection<T>& other) const {
        Collection<T> result;
        for (const auto& pair : data) {
            if (other.has(pair.first)) {
                result.set(pair.first, pair.second);
            }
        }
        return result;
    }
    
    std::vector<Collection<T>> partition(size_t size) const {
        std::vector<Collection<T>> result;
        Collection<T> current;
        size_t count = 0;
        
        for (const auto& pair : data) {
            if (count >= size) {
                result.push_back(std::move(current));
                current = Collection<T>();
                count = 0;
            }
            current.set(pair.first, pair.second);
            count++;
        }
        
        if (!current.empty()) {
            result.push_back(std::move(current));
        }
        
        return result;
    }
    
    Collection<T> sort(std::function<bool(const T&, const T&)> compareFn = nullptr) const {
        std::vector<std::pair<Snowflake, T>> sorted(data.begin(), data.end());
        
        if (compareFn) {
            std::sort(sorted.begin(), sorted.end(), [&](const auto& a, const auto& b) {
                return compareFn(a.second, b.second);
            });
        } else {
            std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
                return a.first < b.first;
            });
        }
        
        Collection<T> result;
        for (const auto& pair : sorted) {
            result.set(pair.first, pair.second);
        }
        return result;
    }
    
    Collection<T> sweep(std::function<bool(const T&, const Snowflake&)> fn) {
        Collection<T> removed;
        auto it = data.begin();
        while (it != data.end()) {
            if (fn(it->second, it->first)) {
                removed.set(it->first, it->second);
                it = data.erase(it);
            } else {
                ++it;
            }
        }
        return removed;
    }
    
    void tap(std::function<void(Collection<T>&)> fn) {
        fn(*this);
    }
};

class EventEmitter {
private:
    std::unordered_map<std::string, std::vector<std::function<void()>>> listeners;
    std::unordered_map<std::string, std::vector<std::function<void()>>> onceListeners;
    std::mutex listenersMutex;
    
public:
    template<typename... Args>
    void on(const std::string& event, std::function<void(Args...)> listener) {
        std::lock_guard<std::mutex> lock(listenersMutex);
        listeners[event].push_back([listener](){ listener(); });
    }
    
    template<typename... Args>
    void once(const std::string& event, std::function<void(Args...)> listener) {
        std::lock_guard<std::mutex> lock(listenersMutex);
        onceListeners[event].push_back([listener](){ listener(); });
    }
    
    template<typename... Args>
    void emit(const std::string& event, Args... args) {
        std::lock_guard<std::mutex> lock(listenersMutex);
        
        if (listeners.find(event) != listeners.end()) {
            for (auto& listener : listeners[event]) {
                try {
                    listener();
                } catch (const std::exception& e) {
                    std::cerr << "Error in event listener: " << e.what() << std::endl;
                }
            }
        }
        
        if (onceListeners.find(event) != onceListeners.end()) {
            for (auto& listener : onceListeners[event]) {
                try {
                    listener();
                } catch (const std::exception& e) {
                    std::cerr << "Error in once event listener: " << e.what() << std::endl;
                }
            }
            onceListeners[event].clear();
        }
    }
    
    void removeAllListeners(const std::string& event = "") {
        std::lock_guard<std::mutex> lock(listenersMutex);
        if (event.empty()) {
            listeners.clear();
            onceListeners.clear();
        } else {
            listeners.erase(event);
            onceListeners.erase(event);
        }
    }
    
    size_t listenerCount(const std::string& event) const {
        std::lock_guard<std::mutex> lock(listenersMutex);
        size_t count = 0;
        if (listeners.find(event) != listeners.end()) {
            count += listeners.at(event).size();
        }
        if (onceListeners.find(event) != onceListeners.end()) {
            count += onceListeners.at(event).size();
        }
        return count;
    }
    
    std::vector<std::string> eventNames() const {
        std::lock_guard<std::mutex> lock(listenersMutex);
        std::set<std::string> names;
        for (const auto& pair : listeners) {
            names.insert(pair.first);
        }
        for (const auto& pair : onceListeners) {
            names.insert(pair.first);
        }
        return std::vector<std::string>(names.begin(), names.end());
    }
};

struct User {
    Snowflake id;
    std::string username;
    std::string discriminator;
    std::string globalName;
    std::optional<std::string> avatar;
    std::optional<bool> bot;
    std::optional<bool> system;
    std::optional<bool> mfaEnabled;
    std::optional<std::string> banner;
    std::optional<uint32_t> accentColor;
    std::optional<std::string> locale;
    std::optional<bool> verified;
    std::optional<std::string> email;
    std::optional<uint32_t> flags;
    std::optional<uint32_t> premiumType;
    std::optional<uint32_t> publicFlags;
    
    User() = default;
    
    std::string tag() const {
        return username + "#" + discriminator;
    }
    
    std::string displayName() const {
        return globalName.value_or(username);
    }
    
    std::string toString() const {
        return "<@" + id + ">";
    }
    
    std::string avatarURL(const std::string& format = "png", uint32_t size = 256) const {
        if (!avatar.has_value()) {
            uint32_t defaultAvatar = std::stoi(discriminator) % 5;
            return "https://cdn.discordapp.com/embed/avatars/" + std::to_string(defaultAvatar) + ".png";
        }
        
        std::string extension = avatar->substr(0, 2) == "a_" ? "gif" : format;
        return "https://cdn.discordapp.com/avatars/" + id + "/" + *avatar + "." + extension + "?size=" + std::to_string(size);
    }
    
    std::string bannerURL(const std::string& format = "png", uint32_t size = 512) const {
        if (!banner.has_value()) return "";
        
        std::string extension = banner->substr(0, 2) == "a_" ? "gif" : format;
        return "https://cdn.discordapp.com/banners/" + id + "/" + *banner + "." + extension + "?size=" + std::to_string(size);
    }
    
    Timestamp createdAt() const {
        uint64_t timestamp = ((std::stoull(id) >> 22) + 1420070400000ULL);
        return std::chrono::system_clock::from_time_t(timestamp / 1000);
    }
    
    bool equals(const User& other) const {
        return id == other.id;
    }
};

struct GuildMember {
    std::optional<User> user;
    std::optional<std::string> nick;
    std::optional<std::string> avatar;
    std::vector<Snowflake> roles;
    Timestamp joinedAt;
    std::optional<Timestamp> premiumSince;
    bool deaf = false;
    bool mute = false;
    std::optional<uint32_t> flags;
    std::optional<bool> pending;
    std::optional<std::string> permissions;
    std::optional<Timestamp> communicationDisabledUntil;
    
    GuildMember() = default;
    
    std::string displayName() const {
        if (nick.has_value()) return *nick;
        if (user.has_value()) return user->displayName();
        return "Unknown User";
    }
    
    std::string toString() const {
        if (user.has_value()) return user->toString();
        return "<@unknown>";
    }
    
    bool hasRole(const Snowflake& roleId) const {
        return std::find(roles.begin(), roles.end(), roleId) != roles.end();
    }
    
    bool isCommunicationDisabled() const {
        if (!communicationDisabledUntil.has_value()) return false;
        return std::chrono::system_clock::now() < *communicationDisabledUntil;
    }
    
    std::chrono::duration<int64_t> communicationDisabledDuration() const {
        if (!communicationDisabledUntil.has_value()) return std::chrono::duration<int64_t>::zero();
        auto now = std::chrono::system_clock::now();
        if (now >= *communicationDisabledUntil) return std::chrono::duration<int64_t>::zero();
        return std::chrono::duration_cast<std::chrono::seconds>(*communicationDisabledUntil - now);
    }
};

struct Role {
    Snowflake id;
    std::string name;
    uint32_t color = 0;
    bool hoist = false;
    std::optional<std::string> icon;
    std::optional<std::string> unicodeEmoji;
    int position = 0;
    std::string permissions = "0";
    bool managed = false;
    bool mentionable = false;
    std::optional<std::map<std::string, std::string>> tags;
    
    Role() = default;
    
    std::string toString() const {
        return "<@&" + id + ">";
    }
    
    Color getColor() const {
        return Color(color);
    }
    
    std::string hexColor() const {
        if (color == 0) return "#000000";
        std::stringstream ss;
        ss << "#" << std::hex << std::setfill('0') << std::setw(6) << color;
        return ss.str();
    }
    
    Timestamp createdAt() const {
        uint64_t timestamp = ((std::stoull(id) >> 22) + 1420070400000ULL);
        return std::chrono::system_clock::from_time_t(timestamp / 1000);
    }
    
    bool hasPermission(PermissionFlag permission) const {
        uint64_t perms = std::stoull(permissions);
        return (perms & static_cast<uint64_t>(permission)) != 0;
    }
    
    bool equals(const Role& other) const {
        return id == other.id;
    }
    
    int comparePositionTo(const Role& other) const {
        return position - other.position;
    }
};

struct Emoji {
    std::optional<Snowflake> id;
    std::optional<std::string> name;
    std::optional<std::vector<Snowflake>> roles;
    std::optional<User> user;
    std::optional<bool> requireColons;
    std::optional<bool> managed;
    std::optional<bool> animated;
    std::optional<bool> available;
    
    Emoji() = default;
    
    std::string toString() const {
        if (!id.has_value()) {
            return name.value_or("");
        }
        
        std::string prefix = (animated.value_or(false)) ? "<a:" : "<:";
        return prefix + name.value_or("") + ":" + *id + ">";
    }
    
    std::string identifier() const {
        if (!id.has_value()) {
            return name.value_or("");
        }
        return name.value_or("") + ":" + *id;
    }
    
    std::string url(const std::string& format = "", uint32_t size = 256) const {
        if (!id.has_value()) return "";
        
        std::string ext = format.empty() ? (animated.value_or(false) ? "gif" : "png") : format;
        return "https://cdn.discordapp.com/emojis/" + *id + "." + ext + "?size=" + std::to_string(size);
    }
    
    Timestamp createdAt() const {
        if (!id.has_value()) return std::chrono::system_clock::now();
        uint64_t timestamp = ((std::stoull(*id) >> 22) + 1420070400000ULL);
        return std::chrono::system_clock::from_time_t(timestamp / 1000);
    }
};

struct Attachment {
    Snowflake id;
    std::string filename;
    std::optional<std::string> description;
    std::optional<std::string> contentType;
    uint64_t size = 0;
    std::string url;
    std::string proxyUrl;
    std::optional<uint32_t> height;
    std::optional<uint32_t> width;
    std::optional<bool> ephemeral;
    
    Attachment() = default;
    
    bool spoiler() const {
        return filename.substr(0, 8) == "SPOILER_";
    }
};

struct EmbedFooter {
    std::string text;
    std::optional<std::string> iconUrl;
    std::optional<std::string> proxyIconUrl;
    
    EmbedFooter() = default;
    EmbedFooter(const std::string& text) : text(text) {}
    EmbedFooter(const std::string& text, const std::string& iconUrl) : text(text), iconUrl(iconUrl) {}
};

struct EmbedImage {
    std::string url;
    std::optional<std::string> proxyUrl;
    std::optional<uint32_t> height;
    std::optional<uint32_t> width;
    
    EmbedImage() = default;
    EmbedImage(const std::string& url) : url(url) {}
};

struct EmbedThumbnail {
    std::string url;
    std::optional<std::string> proxyUrl;
    std::optional<uint32_t> height;
    std::optional<uint32_t> width;
    
    EmbedThumbnail() = default;
    EmbedThumbnail(const std::string& url) : url(url) {}
};

struct EmbedVideo {
    std::optional<std::string> url;
    std::optional<std::string> proxyUrl;
    std::optional<uint32_t> height;
    std::optional<uint32_t> width;
    
    EmbedVideo() = default;
};

struct EmbedProvider {
    std::optional<std::string> name;
    std::optional<std::string> url;
    
    EmbedProvider() = default;
};

struct EmbedAuthor {
    std::string name;
    std::optional<std::string> url;
    std::optional<std::string> iconUrl;
    std::optional<std::string> proxyIconUrl;
    
    EmbedAuthor() = default;
    EmbedAuthor(const std::string& name) : name(name) {}
    EmbedAuthor(const std::string& name, const std::string& iconUrl) : name(name), iconUrl(iconUrl) {}
    EmbedAuthor(const std::string& name, const std::string& iconUrl, const std::string& url) 
        : name(name), iconUrl(iconUrl), url(url) {}
};

struct EmbedField {
    std::string name;
    std::string value;
    std::optional<bool> inline;
    
    EmbedField() = default;
    EmbedField(const std::string& name, const std::string& value, bool inline = false) 
        : name(name), value(value), inline(inline) {}
};

struct Embed {
    std::optional<std::string> title;
    std::optional<std::string> type;
    std::optional<std::string> description;
    std::optional<std::string> url;
    std::optional<Timestamp> timestamp;
    std::optional<uint32_t> color;
    std::optional<EmbedFooter> footer;
    std::optional<EmbedImage> image;
    std::optional<EmbedThumbnail> thumbnail;
    std::optional<EmbedVideo> video;
    std::optional<EmbedProvider> provider;
    std::optional<EmbedAuthor> author;
    std::vector<EmbedField> fields;
    
    Embed() = default;
    
    Embed& setTitle(const std::string& title) {
        this->title = title;
        return *this;
    }
    
    Embed& setDescription(const std::string& description) {
        this->description = description;
        return *this;
    }
    
    Embed& setURL(const std::string& url) {
        this->url = url;
        return *this;
    }
    
    Embed& setTimestamp(const Timestamp& timestamp = std::chrono::system_clock::now()) {
        this->timestamp = timestamp;
        return *this;
    }
    
    Embed& setColor(const Color& color) {
        this->color = color.value;
        return *this;
    }
    
    Embed& setColor(uint32_t color) {
        this->color = color;
        return *this;
    }
    
    Embed& setFooter(const EmbedFooter& footer) {
        this->footer = footer;
        return *this;
    }
    
    Embed& setFooter(const std::string& text, const std::string& iconUrl = "") {
        this->footer = EmbedFooter(text, iconUrl.empty() ? std::optional<std::string>{} : iconUrl);
        return *this;
    }
    
    Embed& setImage(const EmbedImage& image) {
        this->image = image;
        return *this;
    }
    
    Embed& setImage(const std::string& url) {
        this->image = EmbedImage(url);
        return *this;
    }
    
    Embed& setThumbnail(const EmbedThumbnail& thumbnail) {
        this->thumbnail = thumbnail;
        return *this;
    }
    
    Embed& setThumbnail(const std::string& url) {
        this->thumbnail = EmbedThumbnail(url);
        return *this;
    }
    
    Embed& setAuthor(const EmbedAuthor& author) {
        this->author = author;
        return *this;
    }
    
    Embed& setAuthor(const std::string& name, const std::string& iconUrl = "", const std::string& url = "") {
        this->author = EmbedAuthor(name, 
            iconUrl.empty() ? std::optional<std::string>{} : iconUrl,
            url.empty() ? std::optional<std::string>{} : url);
        return *this;
    }
    
    Embed& addField(const EmbedField& field) {
        if (fields.size() < 25) {
            fields.push_back(field);
        }
        return *this;
    }
    
    Embed& addField(const std::string& name, const std::string& value, bool inline = false) {
        return addField(EmbedField(name, value, inline));
    }
    
    Embed& addFields(const std::vector<EmbedField>& fields) {
        for (const auto& field : fields) {
            addField(field);
        }
        return *this;
    }
    
    Embed& setFields(const std::vector<EmbedField>& fields) {
        this->fields = fields;
        if (this->fields.size() > 25) {
            this->fields.resize(25);
        }
        return *this;
    }
    
    Embed& spliceFields(size_t index, size_t deleteCount, const std::vector<EmbedField>& fieldsToAdd = {}) {
        if (index >= fields.size()) return *this;
        
        auto start = fields.begin() + index;
        auto end = start + std::min(deleteCount, fields.size() - index);
        
        fields.erase(start, end);
        fields.insert(fields.begin() + index, fieldsToAdd.begin(), fieldsToAdd.end());
        
        if (fields.size() > 25) {
            fields.resize(25);
        }
        
        return *this;
    }
    
    size_t length() const {
        size_t total = 0;
        if (title.has_value()) total += title->length();
        if (description.has_value()) total += description->length();
        if (footer.has_value()) total += footer->text.length();
        if (author.has_value()) total += author->name.length();
        
        for (const auto& field : fields) {
            total += field.name.length() + field.value.length();
        }
        
        return total;
    }
    
    static Embed fromJSON(const std::string& json) {
        Embed embed;
        return embed;
    }
    
    std::string toJSON() const {
        std::stringstream ss;
        ss << "{";
        
        bool first = true;
        
        if (title.has_value()) {
            if (!first) ss << ",";
            ss << "\"title\":\"" << *title << "\"";
            first = false;
        }
        
        if (description.has_value()) {
            if (!first) ss << ",";
            ss << "\"description\":\"" << *description << "\"";
            first = false;
        }
        
        if (url.has_value()) {
            if (!first) ss << ",";
            ss << "\"url\":\"" << *url << "\"";
            first = false;
        }
        
        if (color.has_value()) {
            if (!first) ss << ",";
            ss << "\"color\":" << *color;
            first = false;
        }
        
        if (!fields.empty()) {
            if (!first) ss << ",";
            ss << "\"fields\":[";
            for (size_t i = 0; i < fields.size(); ++i) {
                if (i > 0) ss << ",";
                ss << "{\"name\":\"" << fields[i].name << "\",\"value\":\"" << fields[i].value << "\"";
                if (fields[i].inline.has_value()) {
                    ss << ",\"inline\":" << (*fields[i].inline ? "true" : "false");
                }
                ss << "}";
            }
            ss << "]";
            first = false;
        }
        
        ss << "}";
        return ss.str();
    }
};

struct ActionRow {
    ComponentType type = ComponentType::ACTION_ROW;
    std::vector<std::variant<struct Button, struct SelectMenu, struct TextInput>> components;
    
    ActionRow() = default;
    
    template<typename T>
    ActionRow& addComponent(const T& component) {
        if (components.size() < 5) {
            components.push_back(component);
        }
        return *this;
    }
    
    template<typename T>
    ActionRow& setComponents(const std::vector<T>& components) {
        this->components.clear();
        for (const auto& component : components) {
            addComponent(component);
        }
        return *this;
    }
};

struct Button {
    ComponentType type = ComponentType::BUTTON;
    ButtonStyle style = ButtonStyle::PRIMARY;
    std::optional<std::string> label;
    std::optional<Emoji> emoji;
    std::optional<std::string> customId;
    std::optional<std::string> url;
    bool disabled = false;
    
    Button() = default;
    
    Button& setLabel(const std::string& label) {
        this->label = label;
        return *this;
    }
    
    Button& setStyle(ButtonStyle style) {
        this->style = style;
        return *this;
    }
    
    Button& setCustomId(const std::string& customId) {
        this->customId = customId;
        return *this;
    }
    
    Button& setURL(const std::string& url) {
        this->url = url;
        this->style = ButtonStyle::LINK;
        return *this;
    }
    
    Button& setEmoji(const Emoji& emoji) {
        this->emoji = emoji;
        return *this;
    }
    
    Button& setDisabled(bool disabled = true) {
        this->disabled = disabled;
        return *this;
    }
    
    static Button primary(const std::string& customId, const std::string& label) {
        Button button;
        button.setStyle(ButtonStyle::PRIMARY).setCustomId(customId).setLabel(label);
        return button;
    }
    
    static Button secondary(const std::string& customId, const std::string& label) {
        Button button;
        button.setStyle(ButtonStyle::SECONDARY).setCustomId(customId).setLabel(label);
        return button;
    }
    
    static Button success(const std::string& customId, const std::string& label) {
        Button button;
        button.setStyle(ButtonStyle::SUCCESS).setCustomId(customId).setLabel(label);
        return button;
    }
    
    static Button danger(const std::string& customId, const std::string& label) {
        Button button;
        button.setStyle(ButtonStyle::DANGER).setCustomId(customId).setLabel(label);
        return button;
    }
    
    static Button link(const std::string& url, const std::string& label) {
        Button button;
        button.setStyle(ButtonStyle::LINK).setURL(url).setLabel(label);
        return button;
    }
};

struct SelectOption {
    std::string label;
    std::string value;
    std::optional<std::string> description;
    std::optional<Emoji> emoji;
    std::optional<bool> defaultSelected;
    
    SelectOption() = default;
    SelectOption(const std::string& label, const std::string& value) : label(label), value(value) {}
    
    SelectOption& setLabel(const std::string& label) {
        this->label = label;
        return *this;
    }
    
    SelectOption& setValue(const std::string& value) {
        this->value = value;
        return *this;
    }
    
    SelectOption& setDescription(const std::string& description) {
        this->description = description;
        return *this;
    }
    
    SelectOption& setEmoji(const Emoji& emoji) {
        this->emoji = emoji;
        return *this;
    }
    
    SelectOption& setDefault(bool defaultSelected = true) {
        this->defaultSelected = defaultSelected;
        return *this;
    }
};

struct SelectMenu {
    ComponentType type = ComponentType::SELECT_MENU;
    std::string customId;
    std::vector<SelectOption> options;
    std::optional<std::string> placeholder;
    std::optional<uint32_t> minValues;
    std::optional<uint32_t> maxValues;
    bool disabled = false;
    
    SelectMenu() = default;
    
    SelectMenu& setCustomId(const std::string& customId) {
        this->customId = customId;
        return *this;
    }
    
    SelectMenu& setPlaceholder(const std::string& placeholder) {
        this->placeholder = placeholder;
        return *this;
    }
    
    SelectMenu& setMinValues(uint32_t minValues) {
        this->minValues = minValues;
        return *this;
    }
    
    SelectMenu& setMaxValues(uint32_t maxValues) {
        this->maxValues = maxValues;
        return *this;
    }
    
    SelectMenu& setDisabled(bool disabled = true) {
        this->disabled = disabled;
        return *this;
    }
    
    SelectMenu& addOption(const SelectOption& option) {
        if (options.size() < 25) {
            options.push_back(option);
        }
        return *this;
    }
    
    SelectMenu& addOptions(const std::vector<SelectOption>& options) {
        for (const auto& option : options) {
            addOption(option);
        }
        return *this;
    }
    
    SelectMenu& setOptions(const std::vector<SelectOption>& options) {
        this->options = options;
        if (this->options.size() > 25) {
            this->options.resize(25);
        }
        return *this;
    }
    
    SelectMenu& spliceOptions(size_t index, size_t deleteCount, const std::vector<SelectOption>& optionsToAdd = {}) {
        if (index >= options.size()) return *this;
        
        auto start = options.begin() + index;
        auto end = start + std::min(deleteCount, options.size() - index);
        
        options.erase(start, end);
        options.insert(options.begin() + index, optionsToAdd.begin(), optionsToAdd.end());
        
        if (options.size() > 25) {
            options.resize(25);
        }
        
        return *this;
    }
};

enum class TextInputStyle {
    SHORT = 1,
    PARAGRAPH = 2
};

struct TextInput {
    ComponentType type = ComponentType::TEXT_INPUT;
    std::string customId;
    TextInputStyle style = TextInputStyle::SHORT;
    std::string label;
    std::optional<std::string> value;
    std::optional<std::string> placeholder;
    std::optional<uint32_t> minLength;
    std::optional<uint32_t> maxLength;
    bool required = false;

    TextInput() = default;

    TextInput& setCustomId(const std::string& id) {
        customId = id;
        return *this;
    }

    TextInput& setStyle(TextInputStyle s) {
        style = s;
        return *this;
    }

    TextInput& setLabel(const std::string& lbl) {
        label = lbl;
        return *this;
    }

    TextInput& setValue(const std::string& val) {
        value = val;
        return *this;
    }

    TextInput& setPlaceholder(const std::string& ph) {
        placeholder = ph;
        return *this;
    }

    TextInput& setMinLength(uint32_t len) {
        minLength = len;
        return *this;
    }

    TextInput& setMaxLength(uint32_t len) {
        maxLength = len;
        return *this;
    }

    TextInput& setRequired(bool req = true) {
        required = req;
        return *this;
    }
}
