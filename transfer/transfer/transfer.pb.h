// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transfer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_transfer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_transfer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_transfer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_transfer_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transfer_2eproto;
namespace transfer {
class Chunk;
class ChunkDefaultTypeInternal;
extern ChunkDefaultTypeInternal _Chunk_default_instance_;
class Reply;
class ReplyDefaultTypeInternal;
extern ReplyDefaultTypeInternal _Reply_default_instance_;
class Stmt1;
class Stmt1DefaultTypeInternal;
extern Stmt1DefaultTypeInternal _Stmt1_default_instance_;
class Stmt2;
class Stmt2DefaultTypeInternal;
extern Stmt2DefaultTypeInternal _Stmt2_default_instance_;
}  // namespace transfer
PROTOBUF_NAMESPACE_OPEN
template<> ::transfer::Chunk* Arena::CreateMaybeMessage<::transfer::Chunk>(Arena*);
template<> ::transfer::Reply* Arena::CreateMaybeMessage<::transfer::Reply>(Arena*);
template<> ::transfer::Stmt1* Arena::CreateMaybeMessage<::transfer::Stmt1>(Arena*);
template<> ::transfer::Stmt2* Arena::CreateMaybeMessage<::transfer::Stmt2>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace transfer {

// ===================================================================

class Stmt1 PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transfer.Stmt1) */ {
 public:
  inline Stmt1() : Stmt1(nullptr) {}
  virtual ~Stmt1();

  Stmt1(const Stmt1& from);
  Stmt1(Stmt1&& from) noexcept
    : Stmt1() {
    *this = ::std::move(from);
  }

  inline Stmt1& operator=(const Stmt1& from) {
    CopyFrom(from);
    return *this;
  }
  inline Stmt1& operator=(Stmt1&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Stmt1& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Stmt1* internal_default_instance() {
    return reinterpret_cast<const Stmt1*>(
               &_Stmt1_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Stmt1& a, Stmt1& b) {
    a.Swap(&b);
  }
  inline void Swap(Stmt1* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Stmt1* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Stmt1* New() const final {
    return CreateMaybeMessage<Stmt1>(nullptr);
  }

  Stmt1* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Stmt1>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Stmt1& from);
  void MergeFrom(const Stmt1& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Stmt1* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transfer.Stmt1";
  }
  protected:
  explicit Stmt1(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_2eproto);
    return ::descriptor_table_transfer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSqlFieldNumber = 1,
    kSiteFieldNumber = 2,
  };
  // string sql = 1;
  void clear_sql();
  const std::string& sql() const;
  void set_sql(const std::string& value);
  void set_sql(std::string&& value);
  void set_sql(const char* value);
  void set_sql(const char* value, size_t size);
  std::string* mutable_sql();
  std::string* release_sql();
  void set_allocated_sql(std::string* sql);
  private:
  const std::string& _internal_sql() const;
  void _internal_set_sql(const std::string& value);
  std::string* _internal_mutable_sql();
  public:

  // int32 site = 2;
  void clear_site();
  ::PROTOBUF_NAMESPACE_ID::int32 site() const;
  void set_site(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_site() const;
  void _internal_set_site(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:transfer.Stmt1)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sql_;
  ::PROTOBUF_NAMESPACE_ID::int32 site_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_2eproto;
};
// -------------------------------------------------------------------

class Stmt2 PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transfer.Stmt2) */ {
 public:
  inline Stmt2() : Stmt2(nullptr) {}
  virtual ~Stmt2();

  Stmt2(const Stmt2& from);
  Stmt2(Stmt2&& from) noexcept
    : Stmt2() {
    *this = ::std::move(from);
  }

  inline Stmt2& operator=(const Stmt2& from) {
    CopyFrom(from);
    return *this;
  }
  inline Stmt2& operator=(Stmt2&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Stmt2& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Stmt2* internal_default_instance() {
    return reinterpret_cast<const Stmt2*>(
               &_Stmt2_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Stmt2& a, Stmt2& b) {
    a.Swap(&b);
  }
  inline void Swap(Stmt2* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Stmt2* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Stmt2* New() const final {
    return CreateMaybeMessage<Stmt2>(nullptr);
  }

  Stmt2* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Stmt2>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Stmt2& from);
  void MergeFrom(const Stmt2& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Stmt2* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transfer.Stmt2";
  }
  protected:
  explicit Stmt2(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_2eproto);
    return ::descriptor_table_transfer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSql1FieldNumber = 1,
    kSql2FieldNumber = 2,
    kSiteFieldNumber = 3,
  };
  // string sql1 = 1;
  void clear_sql1();
  const std::string& sql1() const;
  void set_sql1(const std::string& value);
  void set_sql1(std::string&& value);
  void set_sql1(const char* value);
  void set_sql1(const char* value, size_t size);
  std::string* mutable_sql1();
  std::string* release_sql1();
  void set_allocated_sql1(std::string* sql1);
  private:
  const std::string& _internal_sql1() const;
  void _internal_set_sql1(const std::string& value);
  std::string* _internal_mutable_sql1();
  public:

  // string sql2 = 2;
  void clear_sql2();
  const std::string& sql2() const;
  void set_sql2(const std::string& value);
  void set_sql2(std::string&& value);
  void set_sql2(const char* value);
  void set_sql2(const char* value, size_t size);
  std::string* mutable_sql2();
  std::string* release_sql2();
  void set_allocated_sql2(std::string* sql2);
  private:
  const std::string& _internal_sql2() const;
  void _internal_set_sql2(const std::string& value);
  std::string* _internal_mutable_sql2();
  public:

  // int32 site = 3;
  void clear_site();
  ::PROTOBUF_NAMESPACE_ID::int32 site() const;
  void set_site(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_site() const;
  void _internal_set_site(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:transfer.Stmt2)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sql1_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sql2_;
  ::PROTOBUF_NAMESPACE_ID::int32 site_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_2eproto;
};
// -------------------------------------------------------------------

class Reply PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transfer.Reply) */ {
 public:
  inline Reply() : Reply(nullptr) {}
  virtual ~Reply();

  Reply(const Reply& from);
  Reply(Reply&& from) noexcept
    : Reply() {
    *this = ::std::move(from);
  }

  inline Reply& operator=(const Reply& from) {
    CopyFrom(from);
    return *this;
  }
  inline Reply& operator=(Reply&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Reply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Reply* internal_default_instance() {
    return reinterpret_cast<const Reply*>(
               &_Reply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Reply& a, Reply& b) {
    a.Swap(&b);
  }
  inline void Swap(Reply* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Reply* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Reply* New() const final {
    return CreateMaybeMessage<Reply>(nullptr);
  }

  Reply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Reply>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Reply& from);
  void MergeFrom(const Reply& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Reply* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transfer.Reply";
  }
  protected:
  explicit Reply(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_2eproto);
    return ::descriptor_table_transfer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDoneFieldNumber = 1,
  };
  // string done = 1;
  void clear_done();
  const std::string& done() const;
  void set_done(const std::string& value);
  void set_done(std::string&& value);
  void set_done(const char* value);
  void set_done(const char* value, size_t size);
  std::string* mutable_done();
  std::string* release_done();
  void set_allocated_done(std::string* done);
  private:
  const std::string& _internal_done() const;
  void _internal_set_done(const std::string& value);
  std::string* _internal_mutable_done();
  public:

  // @@protoc_insertion_point(class_scope:transfer.Reply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr done_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_2eproto;
};
// -------------------------------------------------------------------

class Chunk PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transfer.Chunk) */ {
 public:
  inline Chunk() : Chunk(nullptr) {}
  virtual ~Chunk();

  Chunk(const Chunk& from);
  Chunk(Chunk&& from) noexcept
    : Chunk() {
    *this = ::std::move(from);
  }

  inline Chunk& operator=(const Chunk& from) {
    CopyFrom(from);
    return *this;
  }
  inline Chunk& operator=(Chunk&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Chunk& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Chunk* internal_default_instance() {
    return reinterpret_cast<const Chunk*>(
               &_Chunk_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(Chunk& a, Chunk& b) {
    a.Swap(&b);
  }
  inline void Swap(Chunk* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Chunk* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Chunk* New() const final {
    return CreateMaybeMessage<Chunk>(nullptr);
  }

  Chunk* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Chunk>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Chunk& from);
  void MergeFrom(const Chunk& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Chunk* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transfer.Chunk";
  }
  protected:
  explicit Chunk(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_2eproto);
    return ::descriptor_table_transfer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBufferFieldNumber = 1,
  };
  // bytes buffer = 1;
  void clear_buffer();
  const std::string& buffer() const;
  void set_buffer(const std::string& value);
  void set_buffer(std::string&& value);
  void set_buffer(const char* value);
  void set_buffer(const void* value, size_t size);
  std::string* mutable_buffer();
  std::string* release_buffer();
  void set_allocated_buffer(std::string* buffer);
  private:
  const std::string& _internal_buffer() const;
  void _internal_set_buffer(const std::string& value);
  std::string* _internal_mutable_buffer();
  public:

  // @@protoc_insertion_point(class_scope:transfer.Chunk)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr buffer_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Stmt1

// string sql = 1;
inline void Stmt1::clear_sql() {
  sql_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Stmt1::sql() const {
  // @@protoc_insertion_point(field_get:transfer.Stmt1.sql)
  return _internal_sql();
}
inline void Stmt1::set_sql(const std::string& value) {
  _internal_set_sql(value);
  // @@protoc_insertion_point(field_set:transfer.Stmt1.sql)
}
inline std::string* Stmt1::mutable_sql() {
  // @@protoc_insertion_point(field_mutable:transfer.Stmt1.sql)
  return _internal_mutable_sql();
}
inline const std::string& Stmt1::_internal_sql() const {
  return sql_.Get();
}
inline void Stmt1::_internal_set_sql(const std::string& value) {
  
  sql_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Stmt1::set_sql(std::string&& value) {
  
  sql_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transfer.Stmt1.sql)
}
inline void Stmt1::set_sql(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sql_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transfer.Stmt1.sql)
}
inline void Stmt1::set_sql(const char* value,
    size_t size) {
  
  sql_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transfer.Stmt1.sql)
}
inline std::string* Stmt1::_internal_mutable_sql() {
  
  return sql_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Stmt1::release_sql() {
  // @@protoc_insertion_point(field_release:transfer.Stmt1.sql)
  return sql_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Stmt1::set_allocated_sql(std::string* sql) {
  if (sql != nullptr) {
    
  } else {
    
  }
  sql_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sql,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transfer.Stmt1.sql)
}

// int32 site = 2;
inline void Stmt1::clear_site() {
  site_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Stmt1::_internal_site() const {
  return site_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Stmt1::site() const {
  // @@protoc_insertion_point(field_get:transfer.Stmt1.site)
  return _internal_site();
}
inline void Stmt1::_internal_set_site(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  site_ = value;
}
inline void Stmt1::set_site(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_site(value);
  // @@protoc_insertion_point(field_set:transfer.Stmt1.site)
}

// -------------------------------------------------------------------

// Stmt2

// string sql1 = 1;
inline void Stmt2::clear_sql1() {
  sql1_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Stmt2::sql1() const {
  // @@protoc_insertion_point(field_get:transfer.Stmt2.sql1)
  return _internal_sql1();
}
inline void Stmt2::set_sql1(const std::string& value) {
  _internal_set_sql1(value);
  // @@protoc_insertion_point(field_set:transfer.Stmt2.sql1)
}
inline std::string* Stmt2::mutable_sql1() {
  // @@protoc_insertion_point(field_mutable:transfer.Stmt2.sql1)
  return _internal_mutable_sql1();
}
inline const std::string& Stmt2::_internal_sql1() const {
  return sql1_.Get();
}
inline void Stmt2::_internal_set_sql1(const std::string& value) {
  
  sql1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Stmt2::set_sql1(std::string&& value) {
  
  sql1_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transfer.Stmt2.sql1)
}
inline void Stmt2::set_sql1(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sql1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transfer.Stmt2.sql1)
}
inline void Stmt2::set_sql1(const char* value,
    size_t size) {
  
  sql1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transfer.Stmt2.sql1)
}
inline std::string* Stmt2::_internal_mutable_sql1() {
  
  return sql1_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Stmt2::release_sql1() {
  // @@protoc_insertion_point(field_release:transfer.Stmt2.sql1)
  return sql1_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Stmt2::set_allocated_sql1(std::string* sql1) {
  if (sql1 != nullptr) {
    
  } else {
    
  }
  sql1_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sql1,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transfer.Stmt2.sql1)
}

// string sql2 = 2;
inline void Stmt2::clear_sql2() {
  sql2_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Stmt2::sql2() const {
  // @@protoc_insertion_point(field_get:transfer.Stmt2.sql2)
  return _internal_sql2();
}
inline void Stmt2::set_sql2(const std::string& value) {
  _internal_set_sql2(value);
  // @@protoc_insertion_point(field_set:transfer.Stmt2.sql2)
}
inline std::string* Stmt2::mutable_sql2() {
  // @@protoc_insertion_point(field_mutable:transfer.Stmt2.sql2)
  return _internal_mutable_sql2();
}
inline const std::string& Stmt2::_internal_sql2() const {
  return sql2_.Get();
}
inline void Stmt2::_internal_set_sql2(const std::string& value) {
  
  sql2_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Stmt2::set_sql2(std::string&& value) {
  
  sql2_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transfer.Stmt2.sql2)
}
inline void Stmt2::set_sql2(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sql2_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transfer.Stmt2.sql2)
}
inline void Stmt2::set_sql2(const char* value,
    size_t size) {
  
  sql2_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transfer.Stmt2.sql2)
}
inline std::string* Stmt2::_internal_mutable_sql2() {
  
  return sql2_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Stmt2::release_sql2() {
  // @@protoc_insertion_point(field_release:transfer.Stmt2.sql2)
  return sql2_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Stmt2::set_allocated_sql2(std::string* sql2) {
  if (sql2 != nullptr) {
    
  } else {
    
  }
  sql2_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sql2,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transfer.Stmt2.sql2)
}

// int32 site = 3;
inline void Stmt2::clear_site() {
  site_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Stmt2::_internal_site() const {
  return site_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Stmt2::site() const {
  // @@protoc_insertion_point(field_get:transfer.Stmt2.site)
  return _internal_site();
}
inline void Stmt2::_internal_set_site(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  site_ = value;
}
inline void Stmt2::set_site(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_site(value);
  // @@protoc_insertion_point(field_set:transfer.Stmt2.site)
}

// -------------------------------------------------------------------

// Reply

// string done = 1;
inline void Reply::clear_done() {
  done_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Reply::done() const {
  // @@protoc_insertion_point(field_get:transfer.Reply.done)
  return _internal_done();
}
inline void Reply::set_done(const std::string& value) {
  _internal_set_done(value);
  // @@protoc_insertion_point(field_set:transfer.Reply.done)
}
inline std::string* Reply::mutable_done() {
  // @@protoc_insertion_point(field_mutable:transfer.Reply.done)
  return _internal_mutable_done();
}
inline const std::string& Reply::_internal_done() const {
  return done_.Get();
}
inline void Reply::_internal_set_done(const std::string& value) {
  
  done_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Reply::set_done(std::string&& value) {
  
  done_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transfer.Reply.done)
}
inline void Reply::set_done(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  done_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transfer.Reply.done)
}
inline void Reply::set_done(const char* value,
    size_t size) {
  
  done_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transfer.Reply.done)
}
inline std::string* Reply::_internal_mutable_done() {
  
  return done_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Reply::release_done() {
  // @@protoc_insertion_point(field_release:transfer.Reply.done)
  return done_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Reply::set_allocated_done(std::string* done) {
  if (done != nullptr) {
    
  } else {
    
  }
  done_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), done,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transfer.Reply.done)
}

// -------------------------------------------------------------------

// Chunk

// bytes buffer = 1;
inline void Chunk::clear_buffer() {
  buffer_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Chunk::buffer() const {
  // @@protoc_insertion_point(field_get:transfer.Chunk.buffer)
  return _internal_buffer();
}
inline void Chunk::set_buffer(const std::string& value) {
  _internal_set_buffer(value);
  // @@protoc_insertion_point(field_set:transfer.Chunk.buffer)
}
inline std::string* Chunk::mutable_buffer() {
  // @@protoc_insertion_point(field_mutable:transfer.Chunk.buffer)
  return _internal_mutable_buffer();
}
inline const std::string& Chunk::_internal_buffer() const {
  return buffer_.Get();
}
inline void Chunk::_internal_set_buffer(const std::string& value) {
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Chunk::set_buffer(std::string&& value) {
  
  buffer_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transfer.Chunk.buffer)
}
inline void Chunk::set_buffer(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transfer.Chunk.buffer)
}
inline void Chunk::set_buffer(const void* value,
    size_t size) {
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transfer.Chunk.buffer)
}
inline std::string* Chunk::_internal_mutable_buffer() {
  
  return buffer_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Chunk::release_buffer() {
  // @@protoc_insertion_point(field_release:transfer.Chunk.buffer)
  return buffer_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Chunk::set_allocated_buffer(std::string* buffer) {
  if (buffer != nullptr) {
    
  } else {
    
  }
  buffer_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), buffer,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transfer.Chunk.buffer)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace transfer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_transfer_2eproto